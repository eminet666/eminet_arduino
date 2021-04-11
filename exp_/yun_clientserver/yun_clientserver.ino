/* https://wiki.mchobby.be/index.php?title=Arduino_Yun-Guide */

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
YunServer server;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  YunClient client = server.accept();

  if (client) {
    Serial.println("Client"); 
    process(client);
    client.stop();
  }

  delay(500);
}

void process(YunClient client) {
  // Extraction de la commande. 
  // readStringUntil() signifie Lire_chaine_jusqu'a()
  // Donc extraire ce qui se trouve "http://myArduinoYun.local/arduino/" 
  //   et avant le "/" suivant!
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
  // extraction du numéro de broche (un nombre entier)
  pin = client.parseInt();
  
  // S'il y a un "/" après l'entier du numéro de 
  //    broche comme dans ".../arduino/digital/13/1"
  if (client.read() == '/') {
    // Alors lire un autre entier après le "/"
    // cette valeur est l'état de la broche
    // 1 = HIGH, 0 = LOW
    value = client.parseInt();
    digitalWrite(pin, value);
  }
  else {
    // Sinon, sans "/" après ne numéro de broche 
    //     comme dans ".../arduino/digital/13", il
    //     faut simplement lire l'état de l'entrée.
    value = digitalRead(pin);
  }  

  client.print(F("Pin D"));
  client.print(pin);
  client.print(F(" set to "));
  client.println(value);

  // Clé pour le DataStore
  String key = "D";
  key += pin;
  // Stocker la ''clé = valeur'' dans le datastore du Bridge.
  Bridge.put(key, String(value));
}

void analogCommand(YunClient client) {
  int pin, value;
  // Obtenir le numéro de broche depuis l'URL
  pin = client.parseInt();

  // S'il y a une "/" après...
  if (client.read() == '/') {
    // cela signifie que l'on fixe la valeur de la broche 
    value = client.parseInt();
    analogWrite(pin, value);

    // renvoyer une réponse au client
    client.print(F("Pin D"));
    client.print(pin);
    client.print(F(" set to analog "));
    client.println(value);

    // Valeur de la clé pour le DataStore
    String key = "D";
    key += pin;
    // Stockage de la "Clé = Valeur" dans le DataStore
    Bridge.put(key, String(value));
  }
  else {
    // Si pas de "/" après le numéro de broche, c'est que 
    // l'on désire lire la valeur de la broche
    value = analogRead(pin);

    // renvoyer une réponse au client
    client.print(F("Pin A"));
    client.print(pin);
    client.print(F(" reads analog "));
    client.println(value);

    // Stockage de la "Clé = Valeur" dans le DataStore
    String key = "A";
    key += pin;
    Bridge.put(key, String(value));
  }
}

void modeCommand(YunClient client) {
  int pin;
  // Obtenir le numéro de broche depuis l'URL
  pin = client.parseInt();

  if (client.read() != '/') {
    client.println(F("error"));
    return;
  }

  String mode = client.readStringUntil('\r');
  if (mode == "input") {
    // configurer la broche en entrée
    pinMode(pin, INPUT);
    // Informer le client
    client.print(F("Pin D"));
    client.print(pin);
    client.print(F(" configured as INPUT!"));
    return;
  }

  if (mode == "output") {
    // configurer la broche comme sortie
    pinMode(pin, OUTPUT);
    // informer le client
    client.print(F("Pin D"));
    client.print(pin);
    client.print(F(" configured as OUTPUT!"));
    return;
  }

  // Si cette portion de code est exécuter alors
  // la valeur de mode est ni "input" ni "output".
  // Si c'est le cas, alors il y a une erreur
  client.print(F("error: invalid mode "));
  client.print(mode);
}

  





  
