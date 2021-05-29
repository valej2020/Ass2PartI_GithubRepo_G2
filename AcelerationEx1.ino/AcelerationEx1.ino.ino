
/*
 * MPU6886.ino
 * 
 * By: Mike Klepper
 * Date: 26 April 2020
 * 
 * Basically the same as the MPU6886 example sketch but with C -> F conversion
 */

#include "M5Atom.h"

float accX = 0, accY = 0, accZ = 0;
float gyroX = 0, gyroY = 0, gyroZ = 0;
float tempC = 0;
bool IMU6886Flag = false;

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
        M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
        M5.IMU.getAccelData(&accX, &accY, &accZ);
        M5.IMU.getTempData(&tempC);
    
        float tempF = 9*tempC/5 + 32;
    
        Serial.printf("Gyroscope: %.2f,%.2f,%.2f o/s \r\n", gyroX, gyroY, gyroZ);
        Serial.printf("Accelerometer: %.2f,%.2f,%.2f mg\r\n", accX * 1000, accY * 1000, accZ * 1000);
        Serial.printf("Temperature: %.2f C \r\n", tempC);
        Serial.printf("Temperature: %.2f F \r\n", tempF);
        Serial.println("");
    }
    
    delay(500);
    M5.update();
}
