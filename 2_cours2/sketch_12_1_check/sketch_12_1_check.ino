#include <Bridge.h>

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);

  delay(5000);
  Serial.println("************* Initialisation...");
  while (!Serial); // wait for Serial port to connect.
  Serial.println("Communication série ok !");
}

void loop() {
}
