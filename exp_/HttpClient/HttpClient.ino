/* sur connexion serie */
/* https://www.arduino.cc/en/Tutorial/LibraryExamples/HttpClient */

#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  // SerialUSB.begin(9600);
  Serial.begin(9600);

  // while (!SerialUSB); // wait for a serial connection
  while (!Serial); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  client.get("http://www.arduino.cc/asciilogo.txt");

  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    // SerialUSB.print(c);
    Serial.print(c);
  }
  // SerialUSB.flush();
  Serial.flush();

  delay(5000);
}
