// https://www.arduino.cc/en/Reference/EthernetBegin

// Type: dhcp
// Address: 192.168.0.6
// Netmask: 255.255.255.0
// Gateway: 192.168.0.254
// DNS 1: 192.168.0.254

#include <SPI.h> //bibliothèqe pour SPI
#include <Ethernet.h> //bibliothèque pour Ethernet
boolean affiche = true;
byte mac[] = {0x90, 0xA2, 0xDA, 0xF9, 0x11, 0x0D}; // tableau adresse MAC
byte ip[] = {192, 168, 0, 6}; //tableau pour l'adresse IP
IPAddress gateway(192, 168, 0, 254);
IPAddress dns(192, 168, 0, 254);
IPAddress subnet(255,255,255,0);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  // start the serial library:
  Serial.begin(9600);
  Ethernet.begin(mac, ip, dns, gateway, subnet);
}

void loop() {
  delay(1000);
//
//  if (Ethernet.begin(mac) == 0) {
//    Serial.println("Failed to configure Ethernet using DHCP");
//  }
  // print your local IP address:
  Serial.println(Ethernet.localIP());

}
