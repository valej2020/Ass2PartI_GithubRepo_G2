#include "M5Atom.h"
//TESTING BRANCHHHHH
//HOLA
//Working con Accel 2 Branch

//Defining Colors
int WHITE = 0xffffff;
int RED = 0x00ff00;
int GREEN = 0xff0000;
int BLUE = 0x0000ff;
int BLACK = 0x000000;

int colorList[] = {BLACK, GREEN, RED};

float accX_avg = 0;
float accY_avg = 0;
float accZ_avg = 0;

int n_average = 5;

bool IMUFlag = false;

//braking accelereation threshold
float ACCEL_THRESHOLD = 3.0;

int full_screen[25] =
{
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1
};


int *display[1] = {full_screen};

int counter = 0;
bool blink_on = false;



void setup()
{
  M5.begin(true, false, true);
  delay(50);
  M5.dis.drawpix(0, 0xf00000);

  if (M5.IMU.Init() == 0)
  {
    IMUFlag = true;
    Serial.println("[OK] IMU ready");
  }
  else
  {
    IMUFlag = false;
    Serial.println("[ERR] IMU failed!");
  }

}



void loop()
{

  if (M5.Btn.wasPressed())
  {
    counter++; //Increases the counter when button is pressed
    Serial.println("isPressed");
  }

  if (counter == 0)
  {
    //Nothing on screen
    blink_on = false;
    M5.dis.clear();
  }

  else if (counter == 1)
  {
    //Red blink
    blink_on = true;
    M5.dis.clear();
    ALL_ON (display[0], RED);
  }
  else if (counter == 2)
  {
    //White blink
    blink_on = true;
    M5.dis.clear();
    ALL_ON (display[0], WHITE);
  }
  else if (counter == 3)
  {
    // Blinking when riding, RED solid when braking event is detected

    // Finding threshold
    float accX = 0, accY = 0, accZ = 0;
    M5.IMU.getAccelData(&accX, &accY, &accZ);
    // Average the acceleration data
    // find the "running average"
    accX_avg = ((accX_avg * (n_average - 1)) + fabs(accX)) / n_average;
    accY_avg = ((accY_avg * (n_average - 1)) + fabs(accY)) / n_average;
    accZ_avg = ((accZ_avg * (n_average - 1)) + fabs(accZ)) / n_average;

    Serial.println(accZ_avg * 10.0);
    blink_on = false;
    M5.dis.clear();
  if(((accX_avg * 10.0) <=ACCEL_THRESHOLD) || ((accY_avg * 10.0) <=ACCEL_THRESHOLD) || ((accZ_avg * 10.0) <=ACCEL_THRESHOLD) ){
            blink_on = true;
        }else{
            blink_on = false;
        }
        M5.dis.clear();
        ALL_ON(display[0], RED);
  }
  else if (counter == 4)
  {
    // Blinking when riding, RED solid when braking event is detected

    // Finding threshold
    float accX = 0, accY = 0, accZ = 0;
    M5.IMU.getAccelData(&accX, &accY, &accZ);
    // Average the acceleration data
    // find the "running average"
    accX_avg = ((accX_avg * (n_average - 1)) + fabs(accX)) / n_average;
    accY_avg = ((accY_avg * (n_average - 1)) + fabs(accY)) / n_average;
    accZ_avg = ((accZ_avg * (n_average - 1)) + fabs(accZ)) / n_average;

    Serial.println(accZ_avg * 10.0);
    blink_on = false;
    M5.dis.clear();
  if(((accX_avg * 10.0) <=ACCEL_THRESHOLD) || ((accY_avg * 10.0) <=ACCEL_THRESHOLD) || ((accZ_avg * 10.0) <=ACCEL_THRESHOLD) ){
            blink_on = true;
        }else{
            blink_on = false;
        }
        M5.dis.clear();
        ALL_ON(display[0], WHITE);
  }

  Serial.println(counter);

  if (blink_on)
  {
    delay(100);
    M5.dis.clear();
    delay(100);
  }

  if (counter >= 5)
  {
    counter = 0;
  }

  delay(50);
  M5.update();
}


void ALL_ON(int arr[], int color)
{
  for (int i = 0; i < 25; i++)
  {
    M5.dis.drawpix(i, color);
  }
}
