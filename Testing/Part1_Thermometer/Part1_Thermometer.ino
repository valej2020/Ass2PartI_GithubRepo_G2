#include "M5Atom.h"
#include <stdlib.h>

int WHITE = 0xffffff;
int BLACK = 0x000000;

int colors[] = {WHITE,BLACK};
int colorList[] = {BLACK, WHITE};

float accX = 0;
float accY = 0;
float accZ = 0;

bool IMUFlag = false;


float LOW_Threshold = 100;
float HIGH_Threshold = 900;

float scaledAccX = 0;
float scaledAccY = 0;
float scaledAccZ = 0;

int n_average = 15;


//List of screens
int screen_off[25] =
{
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0
};

int full_screen[25] =
{
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1
};

int zero[25] =
{
  0, 0, 1, 1, 0,
  0, 1, 0, 0, 1,
  0, 1, 0, 0, 1,
  0, 1, 0, 0, 1,
  0, 0, 1, 1, 0
};

int one[25] =
{
  0, 0, 1, 0, 0,
  0, 1, 1, 0, 0,
  0, 0, 1, 0, 0,
  0, 0, 1, 0, 0,
  0, 1, 1, 1, 0
};

int two[25] =
{
  0, 1, 1, 1, 0,
  0, 0, 0, 0, 1,
  0, 0, 1, 1, 0,
  0, 1, 0, 0, 0,
  0, 1, 1, 1, 1
};

int three[25] =
{
  0, 1, 1, 1, 0,
  0, 0, 0, 0, 1,
  0, 0, 1, 1, 0,
  0, 0, 0, 0, 1,
  0, 1, 1, 1, 0
};

int four[25] =
{
  0, 0, 0, 1, 0,
  0, 1, 0, 1, 0,
  0, 1, 1, 1, 1,
  0, 0, 0, 1, 0,
  0, 0, 0, 1, 0
};

int five[25] =
{
  0, 1, 1, 1, 1,
  0, 1, 0, 0, 0,
  0, 1, 1, 1, 0,
  0, 0, 0, 0, 1,
  0, 1, 1, 1, 0
};

int six[25] =
{
  0, 0, 1, 1, 0,
  0, 1, 0, 0, 0,
  0, 1, 1, 1, 0,
  0, 1, 0, 0, 1,
  0, 0, 1, 1, 0
};

int seven[25] =
{
  0, 1, 1, 1, 1,
  0, 0, 0, 1, 0,
  0, 0, 1, 0, 0,
  0, 0, 1, 0, 0,
  0, 0, 1, 0, 0
};

int eight[25] =
{
  0, 0, 1, 1, 0,
  0, 1, 0, 0, 1,
  0, 0, 1, 1, 0,
  0, 1, 0, 0, 1,
  0, 0, 1, 1, 0
};

int nine[25] =
{
  0, 0, 1, 1, 0,
  0, 1, 0, 0, 1,
  0, 0, 1, 1, 1,
  0, 0, 0, 0, 1,
  0, 0, 1, 1, 0
};

int dot[25] =
{
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0, 0, 1, 0, 0,
  0, 0, 0, 0, 0
};

//F and C units

int F[25] =
{
  0, 1, 1, 1, 1,
  0, 1, 0, 0, 0,
  0, 1, 1, 1, 0,
  0, 1, 0, 0, 0,
  0, 1, 0, 0, 0
};

int C[25] =
{
  0, 1, 1, 1, 0,
  1, 0, 0, 0, 0,
  1, 0, 0, 0, 0,
  1, 0, 0, 0, 0,
  0, 1, 1, 1, 0
};


int *dispNums[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
int mode_onscreen = 1;
int mode_selected = 1;

bool switched_mode = false;
bool mode_selection_on = true;

void setup()
{
  M5.begin(true, false, true);
  delay(20);

  IMUFlag = M5.IMU.Init() == 0;

  if (!IMUFlag)
  {
    Serial.println("Error initializing the IMU!");
  }
}


void loop()
{
  if (IMUFlag)
  {
    M5.IMU.getAccelData(&accX, &accY, &accZ);
    scaledAccX = accX * 1000;
    scaledAccY = accY * 1000;
    scaledAccZ = accZ * 1000;

    if (abs(scaledAccX) < LOW_Threshold && abs(scaledAccY) < LOW_Threshold && abs(scaledAccZ) > HIGH_Threshold && scaledAccZ > 0)
    {
      //Facing Bottom
      on_screen(screen_off, colorList);
    }
    else if (abs(scaledAccX) < LOW_Threshold && abs(scaledAccY) < LOW_Threshold && abs(scaledAccZ) > HIGH_Threshold && scaledAccZ < 0)
    {
      //Top Facing Code
      switched_mode = false;
      if (mode_selection_on)
            {
                on_screen(dispNums[mode_onscreen], colorList);
            }
            else
            {
                mode_selected = mode_onscreen;

                if (mode_onscreen == 1)
                {
                   
                }
                else if (mode_onscreen == 2)
                {
                 
                }
                else if (mode_onscreen == 5)
                {
                }
            }
    }
     else if (abs(scaledAccX) > HIGH_Threshold && abs(scaledAccY) < LOW_Threshold && abs(scaledAccZ) < LOW_Threshold && scaledAccX > 0)
        {
            mode_selection_on = true;
            //Turn to the right - Go to next mode
            if (!switched_mode)
            {
                mode_onscreen++;
                if (mode_onscreen > 5)
                {
                    mode_onscreen = 1;
                }
                else if (mode_onscreen < 1)
                {
                    mode_onscreen = 5;
                }
            }
            switched_mode = true;
//            on_screen(dispNums[mode_onscreen], colors);
        }

        else if (abs(scaledAccX) > HIGH_Threshold && abs(scaledAccY) < LOW_Threshold && abs(scaledAccZ) < LOW_Threshold && scaledAccX < 0)
        {
            mode_selection_on = true;
           //Turn to the left - Go to previous mode
            if (!switched_mode)
            {
                mode_onscreen--;
                if (mode_onscreen > 5)
                {
                    mode_onscreen = 1;
                }
                else if (mode_onscreen < 1)
                {
                    mode_onscreen = 5;
                }
            }
            switched_mode = true;
        }
  }

 M5.update();

  
}

  void on_screen(int arr[], int color[])
  {
    for (int i = 0; i < 25; i++)
    {
      M5.dis.drawpix(i, color[arr[i]]);
    }
  }
