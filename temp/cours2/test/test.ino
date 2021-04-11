/* récupérer MAC address sur le navigateur : 192.168.0.n */
#include <SPI.h> //bibliothèqe pour SPI
#include <Ethernet.h> //bibliothèque pour Ethernet
boolean affiche = true;
byte mac[] = {0x90, 0xA2, 0xDA, 0xF3, 0x0F, 0x52}; // tableau adresse MAC
byte ip[] = {192, 168, 0, 6}; //tableau pour l'adresse IP

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  // start the serial library:
  Serial.begin(9600);

}

void loop() {
  delay(1000);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
  }
  // print your local IP address:
  Serial.println(Ethernet.localIP());

}
