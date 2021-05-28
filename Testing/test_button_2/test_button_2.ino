/**
 * Button01.ino
 *
 * By: Mike Klepper
 * Date: 26 April 2020
 *
 * Demonstrates all button events implemented in M5Stack's API
 *
 * See blog post on patriot-geek.blogspot.com
 * for instructions.
 */
 

#include "M5Atom.h"

void setup() 
{
  M5.begin(true, false, true);
  delay(10);
}

void loop() 
{
  // Is the button currently down?
//  if(M5.Btn.isPressed())
//  {
//    Serial.println("isPressed");
//  }

  // Is button currently up?
//  if(M5.Btn.isReleased())
//  {
//    Serial.println("isReleased");
//  }

  // Corresponds to onMouseDown
  if(M5.Btn.wasPressed())
  {
    Serial.println("wasPressed");
  }

  // Corresponds to onClick
//  if(M5.Btn.wasReleased())
//  {
//    Serial.println("wasReleased");
//  }

  // Long press
  if(M5.Btn.pressedFor(500))
  {
    Serial.println("pressedFor");
  }

  // Long period of inactivity
//  if(M5.Btn.releasedFor(2000))
//  {
//    Serial.println("releasedFor");
//  }

  delay(50);
  M5.update();
}
