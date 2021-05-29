










/**
 * MorseCode.ino
 *
 * By: Mike Klepper
 * Date: 26 April 2020
 *
 * Converts string stored in message into Morse code
 *
 * See blog post on patriot-geek.blogspot.com
 * for instructions.
 

#include "M5Atom.h"

int GRB_COLOR_WHITE = 0xffffff;
int GRB_COLOR_BLACK = 0x000000;
int GRB_COLOR_RED = 0x00ff00;
int GRB_COLOR_ORANGE = 0xa5ff00;
int GRB_COLOR_YELLOW = 0xffff00;
int GRB_COLOR_GREEN = 0xff0000;
int GRB_COLOR_BLUE = 0x0000ff;
int GRB_COLOR_PURPLE = 0x008080;

int activeColor = GRB_COLOR_RED;

int colorList[] = {GRB_COLOR_BLACK, activeColor};

// Constants used in Farnsworth timing
// See https://morsecode.world/international/timing.html for details
int scale = 200;
int dotDuration = 1 * scale;
int dashDuration = 3 * scale;
int timeBetweenDotsAndDashes = 1 * scale;
int timeBetweenCharacters = 3 * scale;
int spaceDuration = 7 * scale;

String message = F("Trump 2020 Keep America Great");



int dot[25] = 
{
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,1,1,0,
  0,0,1,1,0,
  0,0,0,0,0
};

int dash[25] = 
{
  0,0,0,0,0,
  0,0,0,0,0,
  1,1,1,1,1,
  1,1,1,1,1,
  0,0,0,0,0
};


char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R 
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

char* digits[] = {
  "-----", ".----", "..---", "...--", "....-", ".....",             // 0-5
  "-....", "--...", "---..", "----."                                // 6-9
};


void setup() 
{
  M5.begin(true, false, true);
  delay(20);
}


void loop() 
{
  displayMessageInMorseCode(message);
  finalAnimation();
  delay(2000);
}

void displayMessageInMorseCode(String message)
{
  message.toUpperCase();
  
  int msgLength = message.length();

  Serial.println("");

  for(int i = 0; i < msgLength; i++)
  {
    char currentChar = message.charAt(i);
    String morseCodeForCurrentChar;
    Serial.print(currentChar);
    Serial.print(" ");
    
    if(isAlpha(currentChar))
    {
      morseCodeForCurrentChar = letters[currentChar - 65];
      Serial.print(letters[currentChar - 65]);
      Serial.println(" - Alpha");

      displaySingleMorseCodeCharacter(morseCodeForCurrentChar);
    }
    else if(isDigit(currentChar))
    {
      morseCodeForCurrentChar = digits[currentChar - 48];
      Serial.print(digits[currentChar - 48]);
      Serial.println(" - Digit");

      displaySingleMorseCodeCharacter(morseCodeForCurrentChar);
    }
    else if(isSpace(currentChar))
    {
      Serial.println(" - Space");
      delay(spaceDuration);
    }
  }
}

void displaySingleMorseCodeCharacter(String morseCodeCharacter)
{
  int morseCodeLength = morseCodeCharacter.length();

  for(int i = 0; i < morseCodeLength; i++)
  {
    char currentDotOrDash = morseCodeCharacter.charAt(i);
    Serial.println(currentDotOrDash);

    if(currentDotOrDash == '.')
    {
      M5.dis.clear();
      drawArray(dot, colorList);
      delay(dotDuration);
    }
    else
    {
      M5.dis.clear();
      drawArray(dash, colorList);
      delay(dashDuration);
    }

    M5.dis.clear();
    delay(timeBetweenDotsAndDashes);
  }

  delay(timeBetweenCharacters);
  Serial.println("---------------------");
}


void drawArray(int arr[], int colors[])
{
  for(int i = 0; i < 25; i++)
  {
      M5.dis.drawpix(i, colors[arr[i]]);
  }
}

void fillDisplay(int fillColor)
{
  for(int i = 0; i < 25; i++)
  {
      M5.dis.drawpix(i, fillColor);
  }
}

void finalAnimation()
{
  delay(2000);
  
  M5.dis.clear();
  fillDisplay(GRB_COLOR_RED);
  delay(2000);
  fillDisplay(GRB_COLOR_WHITE);
  delay(2000);
  fillDisplay(GRB_COLOR_BLUE);
  delay(2000);
  M5.dis.clear();
}




/*
 * BrightnessDemo.ino
 * 
 * By: Mike Klepper
 * Date: 16 May 2020
  
 * Demonstrates that changing brightness does NOT require a redraw!
 

#include "M5Atom.h"

void setup() 
{
  M5.begin(true, false, true);
  delay(20);

  for(int i = 0; i < 25; i++)
  {
    M5.dis.drawpix(i, 0xffffff);
  }
}

void loop() 
{
  for(int i = 19; i >= 0; i--)
  {
    M5.dis.setBrightness(i);
    delay(250);
  }

  for (int i = 0; i < 10; i++)
  {
    M5.dis.setBrightness(i);
    delay(50);
  }
  
  M5.update();
}























/**
 * LED-Order.ino
 *
 * By: Mike Klepper
 * Date: 26 April 2020
 *
 * Demonstrates order that pixels are addressed
 *
 * See blog post on patriot-geek.blogspot.com
 * for instructions.



#include "M5Atom.h"

int GRB_COLOR_WHITE = 0xffffff;
int GRB_COLOR_BLACK = 0x000000;

int delayAmt = 1000;

void setup() 
{
  M5.begin(true, false, true);
  delay(50);
}

void loop() 
{
  for(int i = 0; i < 25; i++)
  {
    M5.dis.drawpix(i, GRB_COLOR_WHITE);
    delay(50);
  }
  delay(delayAmt);

  for(int i = 0; i < 25; i++)
  {
    M5.dis.drawpix(i, GRB_COLOR_BLACK);
    delay(50);
  }
  
  delay(delayAmt);
  M5.update();
}
 */



/*
 * FourPixels.ino
 * By: Mike Klepper
 * Date: 16 May 2020
 * Demonstrates GRB color order for the LEDs as well as axis orientation
 

#include "M5Atom.h"

void setup() 
{
  M5.begin(true, false, true);
  delay(20);
}

void loop() 
{
  M5.dis.drawpix(0, 0, 0xffffff); // White
  M5.dis.drawpix(4, 0, 0x00ff00); // Red
  M5.dis.drawpix(0, 4, 0xff0000); // Green
  M5.dis.drawpix(4, 4, 0x0000ff); // Blue
  Serial.println(F("Pixels are on"));
  delay(250);
  
  M5.dis.clear();
  Serial.println(F("Pixels are off"));
  delay(100);
  
  M5.update();
}

*/

/*
 * single pixel
 * By: Mike Klepper
 * Date: 16 May 2020
 * Introduces the M5Atom API

//white
#include "M5Atom.h"

void setup() 
{
  M5.begin(true, false, true);
  delay(20);
}

void loop() 
{
  M5.dis.drawpix(0, 0, 0xffffff);
  Serial.println(F("Pixel is on"));
  delay(100);
  M5.dis.clear();
  Serial.println(F("Pixel is off"));
  delay(250);
  M5.update();
}

 */
