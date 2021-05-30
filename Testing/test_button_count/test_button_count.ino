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

int colorList[] = {BLACK,GREEN,RED};

float accX = 0;
float accY = 0;
float accZ = 0;

int n_average = 5;

bool IMUFlag = false;

//braking accelereatio threshold 
float ACCEL_THRESHOLD = 3.0;

int full_screen[25] =
    {
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1};


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
    //Only 1 red LED
    blink_on = false;
    M5.dis.clear();
    M5.dis.drawpix(4, 0x00f000);
  }
  else if (counter == 4)
  {
    //Only 1 red LED
    blink_on = false;
    M5.dis.clear();
    M5.dis.drawpix(5, 0x00f000);
  }

  Serial.println(counter);

  if (blink_on)
  {
    delay(100);
    M5.dis.clear();
    delay(100);
  }

  if (counter >= 4)
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
