#include <Bridge.h>
#include <FileIO.h>
boolean messageOK = true;

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);

  delay(5000);
  message("Initialisation...");
  while (!Serial); // wait for Serial port to connect.
  message("Communication série OK !");

  // Setup File IO
  if(!FileSystem.begin()){
    message("FileSystem Failed !");
    return;
  }
  else {
     message("FileSystem OK !");
  }

  File monFichier;
  if(!FileSystem.open("/mnt/sda1/arduino/fichier.txt", FILE_WRITE)) {
    errmsg("impossible d'ouvrir le fichier !");
    return;
  }
  else {
    message("Fichier ouvert");
    monFichier.close();
    message("Fichier clos");
  }

}

void loop() {
}

/* FUNCTIONS */
void message(String s){
  if (messageOK){
    Serial.println("--- "+s);
  }
}
void errmsg(String s){
  if (messageOK){
    Serial.println("ERROR "+s);
  }
}
