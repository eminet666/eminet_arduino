/* https://www.gotronic.fr/pj2-mf52type-1554.pdf */
#include <math.h>
#include <Bridge.h>
#include <FileIO.h>
File monFichier;

double Thermister(int RawADC) {
    double Temp;
    Temp = log(((10240000/RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp );
    Temp = Temp -273.15;
    return Temp;
}

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
    Serial.println("ERREUR FileSystem Failed !");
    return;
  }
  else {
     Serial.println("--- FileSystem OK !");
  }
}

void loop() {
    double degre = Thermister(analogRead(0));

    File monFichier = FileSystem.open("/mnt/sd/arduino/www/temperature.txt", FILE_APPEND);
    if(monFichier) {
      Serial.print("--- Fichier ouvert : ");
      Serial.print(degre);  
      monFichier.println(degre);             // écriture dans le fichier        
      monFichier.close();
      Serial.println("C Fichier clos ---");
      
    }
    else Serial.println("ERREUR Fichier inaccessible");

    delay(5000);
}
