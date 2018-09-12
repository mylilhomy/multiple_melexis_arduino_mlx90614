// Include the libraries we need
#include <UIPEthernet.h>
#include <UIPUdp.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 3

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress insideThermometer;
// Network Settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 211);
IPAddress gateway(192, 168, 0, 200);
IPAddress subnet(255, 255, 255, 0);
IPAddress loxoneIP(192, 168, 1, 210);
unsigned int localPort = 7002;                     // Local UDP port to listen on
unsigned int loxonePort = 7001;                    // Recipient UDP Port

EthernetUDP Udp;                                   // An EthernetUDP instance to send and receive packets over UDP

/*
   Setup function. Here we do the basics
*/
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  sensors.begin();
  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0");
  // set the resolution to 9 bit (Each Dallas/Maxim device is capable of several different resolutions)
  sensors.setResolution(insideThermometer, 12);

    // start Ethernet
  Ethernet.begin(mac, ip);
  // Start UDP
  Udp.begin(localPort);
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  // method 1 - slower
  //Serial.print("Temp C: ");
  //Serial.print(sensors.getTempC(deviceAddress));
  //Serial.print(" Temp F: ");
  //Serial.print(sensors.getTempF(deviceAddress)); // Makes a second call to getTempC and then converts to Fahrenheit

  // method 2 - faster
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.println(tempC);
//  sendUDP("Temperatur Halle 1: ");
  String temp = "Temperatur Halle 1: " + String(tempC, 2);
  sendUDP(temp);

}
void sendUDP(String text)
{
  Udp.beginPacket(loxoneIP, loxonePort);
  // Udp.write("Test");
  Udp.print(text);
  Udp.endPacket();
  delay(10);
}
/*
   Main function. It will request the tempC from the sensors and display on Serial.
*/
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  sensors.requestTemperatures(); // Send the command to get temperatures
  printTemperature(insideThermometer); // Use a simple function to print out the data
}

