#include <Bridge.h>
#include <FileIO.h>
 File monFichier;

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);

  delay(5000);
  Serial.println("--- Initialisation...");
  while (!Serial); // wait for Serial port to connect.
  Serial.println("--- Communication série OK !");

  // Setup File IO
  if(!FileSystem.begin()){
    Serial.println("ERROR FileSystem Failed !");
    return;
  }
  else {
     Serial.println("--- FileSystem OK !");
  }

  if(!FileSystem.open("/mnt/sda1/arduino/fichier.txt", FILE_WRITE)) {
    Serial.println("ERROR Unable to open File !");
    return;
  }
  else {
    Serial.println("--- Fichier ouvert");
    monFichier.close();
    Serial.println("--- Fichier clos");
  }
}

void loop() {
}
