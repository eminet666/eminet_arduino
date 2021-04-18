/* https://www.gotronic.fr/pj2-mf52type-1554.pdf */
/* connexion série */
#include <math.h>
#include <Bridge.h>
#include <FileIO.h>
#include <Console.h>
File monFichier;

double Thermister(int RawADC) {
    double Temp;
    Temp = log(((10240000/RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp );
    Temp = Temp -273.15;
    return Temp;
}

void setup() {
  delay(5000);
  Console.println("--- Initialisation...");
  Bridge.begin();

  // Setup File IO
  if(!FileSystem.begin()){
    Console.println("ERREUR FileSystem Failed !");
    return;
  }
  else {
     Console.println("--- FileSystem OK !");
  }
}

void loop() {
    double degre = Thermister(analogRead(0));

    File monFichier = FileSystem.open("/mnt/sd/arduino/www/temperature.txt", FILE_APPEND);
    if(monFichier) {
//      Console.print(DateTime.now();
//      Console.println(" - ");  
      Console.print(degre); 
      Console.println("°C");  
      monFichier.println(degre);             // écriture dans le fichier        
      monFichier.close();      
    }
    else Console.println("ERREUR Fichier inaccessible");

    delay(5000);
}
