/*
 * AccelerometerTest02.ino
 * 
 * By: Mike Klepper
 * Date: 26 April 2020
 * 
 * Displays arrow indicating device orientation based on info from the MPU6886
 */
 

#include "M5Atom.h"

int GRB_COLOR_WHITE = 0xffffff;
int GRB_COLOR_BLACK = 0x000000;
int GRB_COLOR_RED = 0x00ff00;
int GRB_COLOR_ORANGE = 0xa5ff00;
int GRB_COLOR_YELLOW = 0xffff00;
int GRB_COLOR_GREEN = 0xff0000;
int GRB_COLOR_BLUE = 0x0000ff;
int GRB_COLOR_PURPLE = 0x008080;

int upArrow[25] = 
{
    0,0,1,0,0,
    0,1,1,1,0,
    1,0,1,0,1,
    0,0,1,0,0,
    0,0,1,0,0
};

int downArrow[25] = 
{
    0,0,1,0,0,
    0,0,1,0,0,
    1,0,1,0,1,
    0,1,1,1,0,
    0,0,1,0,0
};

int leftArrow[25] = 
{
    0,0,1,0,0,
    0,1,0,0,0,
    1,1,1,1,1,
    0,1,0,0,0,
    0,0,1,0,0
};

int rightArrow[25] = 
{
    0,0,1,0,0,
    0,0,0,1,0,
    1,1,1,1,1,
    0,0,0,1,0,
    0,0,1,0,0
};

int roundShape[25] = 
{
    0,1,1,1,0,
    1,0,0,0,1,
    1,0,0,0,1,
    1,0,0,0,1,
    0,1,1,1,0
};

int circleWithX[25] = 
{
    0,1,1,1,0,
    1,0,2,0,1,
    1,2,2,2,1,
    1,0,2,0,1,
    0,1,1,1,0
};


int delayAmt = 1000;

int colorList[] = {GRB_COLOR_BLACK, GRB_COLOR_PURPLE, GRB_COLOR_YELLOW};

float accX = 0;
float accY = 0;
float accZ = 0;

bool IMU6886Flag = false;

/*
 * Screen Up: 
 * |accX| < LOW_TOL -15, |accY| < LOW_TOL, accZ ~ -980
 * 
 * Screen Down: 
 * |accX| < LOW_TOL -7, |accY| < LOW_TOL 3, accZ ~ 1020
 * 
 * Note Up: 
 * |accX| < LOW_TOL -7, accY ~ 1000, |accZ| < LOW_TOL
 * 
 * Note Down: 
 * |accX| < LOW_TOL -7, accY ~ -1000, |accZ| < LOW_TOL
 * 
 * Reset Up: 
 * accX ~ 990, |accY| < LOW_TOL, |accZ| < LOW_TOL
 * 
 * Reset Down: 
 * accX ~ -1000, |accY| < LOW_TOL - 10, |accZ| < LOW_TOL, -20
 */

float LOW_TOL = 100;
float HIGH_TOL = 900;

float scaledAccX = 0;
float scaledAccY = 0;
float scaledAccZ = 0;

void setup() 
{
    M5.begin(true, false, true);
    delay(20);
    
    IMU6886Flag = M5.IMU.Init() == 0;
  
    if(!IMU6886Flag)
    {
        Serial.println("Error initializing the IMU! :-(");
    }
}

void loop() 
{
    if(IMU6886Flag)
    {
        M5.IMU.getAccelData(&accX, &accY, &accZ);

        Serial.printf("Accel: %.2f, %.2f, %.2f mg\r\n", accX * 1000, accY * 1000, accZ * 1000);
        
        scaledAccX = accX * 1000;
        scaledAccY = accY * 1000;
        scaledAccZ = accZ * 1000;

        if(abs(scaledAccX) < LOW_TOL && abs(scaledAccY) < LOW_TOL && abs(scaledAccZ) > HIGH_TOL && scaledAccZ > 0)
        {
            drawArray(roundShape, colorList);
        }

        else if(abs(scaledAccX) < LOW_TOL && abs(scaledAccY) < LOW_TOL && abs(scaledAccZ) > HIGH_TOL && scaledAccZ < 0)
        {
            drawArray(circleWithX, colorList);
        }
        
        else if(abs(scaledAccX) < LOW_TOL && abs(scaledAccY) > HIGH_TOL && abs(scaledAccZ) < LOW_TOL && scaledAccY > 0)
        {
            drawArray(upArrow, colorList);
        }

        else if(abs(scaledAccX) < LOW_TOL && abs(scaledAccY) > HIGH_TOL && abs(scaledAccZ) < LOW_TOL && scaledAccY < 0)
        {
            drawArray(downArrow, colorList);
        }

        else if(abs(scaledAccX) > HIGH_TOL && abs(scaledAccY) < LOW_TOL && abs(scaledAccZ) < LOW_TOL && scaledAccX > 0)
        {
            drawArray(leftArrow, colorList);
        }

        else if(abs(scaledAccX) > HIGH_TOL && abs(scaledAccY) < LOW_TOL && abs(scaledAccZ) < LOW_TOL && scaledAccX < 0)
        {
            drawArray(rightArrow, colorList);
        }
        else
        {
            M5.dis.clear();
        }
    }

    delay(250);
    M5.update();
}


void drawArray(int arr[], int colors[])
{
    for(int i = 0; i < 25; i++)
    {
        M5.dis.drawpix(i, colors[arr[i]]);
    }
}
