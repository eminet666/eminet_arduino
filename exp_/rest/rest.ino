/* http://projet.eu.org/pedago/sin/tutos/arduino_yun.pdf */
#include<Bridge.h>
#include<YunServer.h>
#include<YunClient.h>

// Démarre une instance de YunServer, qui réceptionnera
// toutes les requêtes transférées par le serveur web côté GNU/Linux
YunServer server;
void setup(){
  // Démarre une instance du Bridge    
  Bridge.begin();
  while (!Serial); // wait for Serial port to connect.
  Serial.println("Communication Série 0K\n");
  
  // Lance l'écoute du YunServer sur le réseau    
  server.listenOnLocalhost();    
  server.begin();
}

void loop(){
 
  YunClient client = server.accept();     // Réceptionne les éventuels clients   
 
  if (client) {                           // Un client s'est-il connecté ? 
    Serial.println("Client");    
    process(client);                      // On traite la requête   
  }
}

void process(YunClient client) {
  String command = client.readStringUntil('/');
  if (command == "digital") {
    digitalCommand(client);
  }

  if (command == "analog") {
    analogCommand(client);
  }

  if (command == "mode") {
    modeCommand(client);
  }
}

void digitalCommand(YunClient client) {
  int pin, value;
  pin = client.parseInt();
  if (client.read() == '/') {
    value = client.parseInt();
    digitalWrite(pin, value);
  }
  else {
    value = digitalRead(pin);
  }
  
  client.print(F("Pin D"));
  client.print(pin);
  client.print(F(" set to "));
  client.println(value);
  String key = "D";
  key += pin;
  Bridge.put(key, String(value));
}

void analogCommand(YunClient client) {
  int pin, value;
  pin = client.parseInt();
  if (client.read() == '/') {
    value = client.parseInt();
    analogWrite(pin, value);
    // Send feedback to client
    client.print(F("Pin D"));
    client.print(pin);
    client.print(F(" set to analog "));
    client.println(value);
    String key = "D";
    key += pin;
    Bridge.put(key, String(value));
  }
  else {
    value = analogRead(pin);
    client.print(F("Pin A"));
    client.print(pin);
    client.print(F(" reads analog "));
    client.println(value);
    String key = "A";
    key += pin;
    Bridge.put(key, String(value));
  }
}

void modeCommand(YunClient client) {
  int pin;
  pin = client.parseInt();
  if (client.read() != '/') {
    client.println(F("error"));
    return;
  }  

  String mode = client.readStringUntil('\r');
  if (mode == "input") {
    pinMode(pin, INPUT);
    // Send feedback to client
    client.print(F("Pin D"));
    client.print(pin);
    client.print(F(" configured as INPUT!"));
    return;
  }
  if (mode == "output") {
    pinMode(pin, OUTPUT);
    // Send feedback to client
    client.print(F("Pin D"));
    client.print(pin);
    client.print(F(" configured as OUTPUT!"));
    return;
  }

  client.print(F("error: invalid mode "));

  client.print(mode);
}
