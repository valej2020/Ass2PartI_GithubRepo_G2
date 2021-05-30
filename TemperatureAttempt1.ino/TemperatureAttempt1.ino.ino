/*
 * code based on TemperatureSensor01.in
 * By: Mike Klepper
 * Date: 26 April 2020
 * Changes display based on internal temperature
 * 
 * In normal operation, the device is measuring temperature and recording it at a predetermined interval, and the
screen displays nothing
based also on https://github.com/bobbytech/TimeAlarms
//time code https://www.instructables.com/Making-a-Clock-With-M5stick-C-Using-Arduino-IDE-RT/
 
//Alarm.timerRepeat(Period, TimerFunction);
  Description:  Continuously calls user provided TimerFunction  after the given period in seconds has elapsed. 
  */
#include "M5Atom.h"
#include <Time.h>
#include <TimeAlarms.h>


int GRB_COLOR_WHITE = 0xffffff;
int GRB_COLOR_BLACK = 0x000000;
int GRB_COLOR_RED = 0x00ff00;
int GRB_COLOR_ORANGE = 0xa5ff00;
int GRB_COLOR_YELLOW = 0xffff00;
int GRB_COLOR_GREEN = 0xff0000;
int GRB_COLOR_BLUE = 0x0000ff;
int GRB_COLOR_PURPLE = 0x008080;

float lowTempF = 103;
float highTempF = 105;
const int Period = 15; /*constant time interval*/

float tempC = 0;
bool IMU6886Flag = false;


#include <Time.h>
#include <TimeAlarms.h>

void setup()
{
  Serial.begin(9600);
  setTime(8,29,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms 
  Alarm.alarmRepeat(8,30,0, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(17,45,0,EveningAlarm);  // 5:45pm every day 
  Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // 8:30:30 every Saturday 

 
  Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds    
  Alarm.timerOnce(10, OnceOnly);             // called once after 10 seconds 
}

void  loop(){  
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

// functions to be called when an alarm triggers:
void MorningAlarm(){
  Serial.println("Alarm: - turn lights off");    
}

void EveningAlarm(){
  Serial.println("Alarm: - turn lights on");           
}

void WeeklyAlarm(){
  Serial.println("Alarm: - its Monday Morning");      
}

void ExplicitAlarm(){
  Serial.println("Alarm: - this triggers only at the given date and time");       
}

void Repeats(){
  Serial.println("15 second timer");         
}

void OnceOnly(){
  Serial.println("This timer only triggers once");  
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}



/*
void setup()
{
  M5.begin(true, false, true);
    delay(20);
  Serial.begin(9600);
  setTime(8,29,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms 
  Alarm.alarmRepeat(8,30,0, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(17,45,0,EveningAlarm);  // 5:45pm every day 
  Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // 8:30:30 every Saturday 

 
  Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds    
  Alarm.timerOnce(10, OnceOnly);             // called once after 10 seconds 
}

void Repeats(){
  Serial.println("15 second timer");
  M5.IMU.getTempData(&tempC);
  Serial.printf(" Temp : %.2f C \r\n", tempC);
  float tempF = tempC * 9 / 5 + 32;
  Serial.printf(" Temp : %.2f F \r\n", tempF);         
}

void fillDisplay(int fillColor)
{
    for(int i = 0; i < 25; i++)
    {
        M5.dis.drawpix(i, fillColor);
    }
}

/*
void loop() 
{
    if(IMU6886Flag)
    {
        M5.IMU.getTempData(&tempC);
        Serial.printf(" Temp : %.2f C \r\n", tempC);
        float tempF = tempC * 9 / 5 + 32;
        Serial.printf(" Temp : %.2f F \r\n", tempF);
    
        if(tempF < lowTempF)
        {
            fillDisplay(GRB_COLOR_BLUE);
        }
        else if(tempF > highTempF)
        {
            fillDisplay(GRB_COLOR_RED);
        }
        else
        {
            fillDisplay(GRB_COLOR_GREEN);
        }
        
        delay(500);
        M5.update();
    }
}
*/
