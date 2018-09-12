#include <UIPEthernet.h>
#include <UIPUdp.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 178, 207);
IPAddress gateway(192, 168, 178, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress loxoneIP(192, 168, 178, 200);
unsigned int localPort = 7002;                     // Local UDP port to listen on
unsigned int loxonePort = 7001;                    // Recipient UDP Port

EthernetUDP Udp;                                   // An EthernetUDP instance to send and receive packets over UDP

void setup() {
  // start Ethernet
  Ethernet.begin(mac, ip);
  // Start UDP
  Udp.begin(localPort);
}

void loop() {
  sendUDP("Hello World");
}


void sendUDP(String text)
{
  Udp.beginPacket(loxoneIP, loxonePort);
  // Udp.write("Test");
  Udp.print(text);
  Udp.endPacket();
  delay(10);
}
