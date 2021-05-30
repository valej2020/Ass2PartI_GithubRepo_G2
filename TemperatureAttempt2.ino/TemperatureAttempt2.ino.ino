#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
bool BMP180connected = false;

volatile bool get_temp;

#define PIN_SDA 21
#define PIN_SCL 22
#define PIN_LED 32

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

// With critical section
void IRAM_ATTR onTime() {
    portENTER_CRITICAL_ISR(&timerMux);
    get_temp = true;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void blinkLED(){
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_LED, LOW);
}

void setup() {
    Serial.begin(115200);
  
  // Attribute Pins for I2C bus
  Wire.begin(18, 5);

  if (!bmp.begin()) {
      Serial.println("Could not find a valid BMP085 sensor, check wiring!");
      //while (1) {}
  } else {
    BMP180connected = true;
  }

  // Configure LED Output
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

    // Configure Prescaler to 80, as our timer runs @ 80Mhz
    // Giving an output of 80,000,000 / 80 = 1,000,000 ticks / second
    timer = timerBegin(0, 80, true);                
    timerAttachInterrupt(timer, &onTime, true);    
    
  // Fire Interrupt every 1s (1 million ticks)
    timerAlarmWrite(timer, 2000000, true);      
    timerAlarmEnable(timer);
}

void loop() {
    if ( get_temp ) {
    // You can comment Enter/ Exit critical section
    portENTER_CRITICAL(&timerMux);
        get_temp = false;
        portEXIT_CRITICAL(&timerMux);
    
    if ( BMP180connected ) {
      blinkLED();
      Serial.printf("Temperature is %.1f°C \n", bmp.readTemperature()); 
    }
    }
}
