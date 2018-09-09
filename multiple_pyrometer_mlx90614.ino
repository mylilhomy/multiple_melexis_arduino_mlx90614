#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library

// Create an IRTherm object to interact with throughout
IRTherm therm1;
IRTherm therm2;
IRTherm therm3;
IRTherm therm4;
IRTherm therm5;
IRTherm therm6;
IRTherm therm7;
IRTherm therm8;
IRTherm therm9;
IRTherm therm10;
IRTherm therm11;
IRTherm therm12;
IRTherm therm13;
IRTherm therm14;
IRTherm therm15;
IRTherm therm16;

void setup() {

  Serial.begin(9600); // Initialize Serial to log output

  // Initialize thermal IR sensor
  therm1.begin(0x5A);
  therm2.begin(0x5B);
  therm3.begin(0x5C);
  therm4.begin(0x5D);
  therm5.begin(0x5E);
  therm6.begin(0x5F);
  therm7.begin(0x60);
  therm8.begin(0x61);
  therm9.begin(0x62);
  therm10.begin(0x63);
  therm11.begin(0x64);
  therm12.begin(0x65);
  therm13.begin(0x66);
  therm14.begin(0x67);
  therm15.begin(0x68);
  therm16.begin(0x69);

  //therm.setUnit(TEMP_C); // Set the library's units to Farenheit
  // Alternatively, TEMP_F can be replaced with TEMP_C for Celsius
}

void pyrometer(IRTherm therm) {
  if (therm.read()) {
    String thermObject = "Object: " +
                         String(therm.readAddress(), HEX) +
                         " " +
                         String(therm.object(), 2);
    String thermAmbient = "Ambient: " +
                          String(therm.readAddress(), HEX) +
                          " " +
                          String(therm.ambient(), 2);

    Serial.println(thermObject);
    Serial.println(thermAmbient);

    delay(100);
  }

  void loop() {
    
    pyrometer(therm1);
    pyrometer(therm2);
    pyrometer(therm3);
    pyrometer(therm4);
    pyrometer(therm5);
    pyrometer(therm6);
    pyrometer(therm7);
    pyrometer(therm8);
    pyrometer(therm9);
    pyrometer(therm10);
    pyrometer(therm11);
    pyrometer(therm12);
    pyrometer(therm13);
    pyrometer(therm14);
    pyrometer(therm15);
    pyrometer(therm16);
    
  }
