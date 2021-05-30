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

int counter = 0;
bool blink_on = false;

void loop()
{

  if (M5.Btn.wasPressed())
  {
    counter++; //Increases the counter everytime the button is pressed
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
    M5.dis.drawpix(0, 0x00f000);
    M5.dis.drawpix(1, 0x00f000);
    M5.dis.drawpix(2, 0x00f000);
    M5.dis.drawpix(3, 0x00f000);
    M5.dis.drawpix(4, 0x00f000);
    M5.dis.drawpix(5, 0x00f000);
    M5.dis.drawpix(6, 0x00f000);
    M5.dis.drawpix(7, 0x00f000);
    M5.dis.drawpix(8, 0x00f000);
    M5.dis.drawpix(9, 0x00f000);
    M5.dis.drawpix(10, 0x00f000);
    M5.dis.drawpix(11, 0x00f000);
    M5.dis.drawpix(12, 0x00f000);
    M5.dis.drawpix(13, 0x00f000);
    M5.dis.drawpix(14, 0x00f000);
    M5.dis.drawpix(15, 0x00f000);
    M5.dis.drawpix(16, 0x00f000);
    M5.dis.drawpix(17, 0x00f000);
    M5.dis.drawpix(18, 0x00f000);
    M5.dis.drawpix(19, 0x00f000);
    M5.dis.drawpix(20, 0x00f000);
    M5.dis.drawpix(21, 0x00f000);
    M5.dis.drawpix(22, 0x00f000);
    M5.dis.drawpix(23, 0x00f000);
    M5.dis.drawpix(24, 0x00f000);
    M5.dis.drawpix(25, 0x00f000);
  }
  else if (counter == 2)
  {
    //White blink 
    blink_on = true;
    M5.dis.clear();
    M5.dis.drawpix(0, 0x707070);
    M5.dis.drawpix(1, 0x707070);
    M5.dis.drawpix(2, 0x707070);
    M5.dis.drawpix(3, 0x707070);
    M5.dis.drawpix(4, 0x707070);
    M5.dis.drawpix(5, 0x707070);
    M5.dis.drawpix(6, 0x707070);
    M5.dis.drawpix(7, 0x707070);
    M5.dis.drawpix(8, 0x707070);
    M5.dis.drawpix(9, 0x707070);
    M5.dis.drawpix(10, 0x707070);
    M5.dis.drawpix(11, 0x707070);
    M5.dis.drawpix(12, 0x707070);
    M5.dis.drawpix(13, 0x707070);
    M5.dis.drawpix(14, 0x707070);
    M5.dis.drawpix(15, 0x707070);
    M5.dis.drawpix(16, 0x707070);
    M5.dis.drawpix(17, 0x707070);
    M5.dis.drawpix(18, 0x707070);
    M5.dis.drawpix(19, 0x707070);
    M5.dis.drawpix(20, 0x707070);
    M5.dis.drawpix(21, 0x707070);
    M5.dis.drawpix(22, 0x707070);
    M5.dis.drawpix(23, 0x707070);
    M5.dis.drawpix(24, 0x707070);
    M5.dis.drawpix(25, 0x707070);
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
