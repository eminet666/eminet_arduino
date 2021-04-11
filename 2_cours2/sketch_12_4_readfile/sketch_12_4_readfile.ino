#include <Bridge.h>
#include <FileIO.h>

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

  /* PHASE D'ECRITURE */
  randomSeed(analogRead(A0)); //initialise nombre aléatoire
  File monFichier = FileSystem.open("/mnt/sd/arduino/aleatoire.txt", FILE_WRITE);
  if(monFichier) {
    Serial.println("--- Fichier ouvert");
    monFichier.println("nombres aléatoires"); //écriture dans le fichier    

    for (int n = 0; n < 10; n++){             // boucle d'écriture
      int nbAlea=random(0,10000);             // tirage d'un nombre entre 0 et 10000
      Serial.println("    Ecriture de "+String(nbAlea));
      monFichier.println(nbAlea);             // écriture dans le fichier        
    }
    monFichier.close();
    Serial.println("--- Fichier clos");
    
  }
  else Serial.println("ERREUR Fichier inaccessible");

  /* PHASE DE LECTURE */
  Serial.println("--- ouverture du fichier en lecture");
  File monFichier2 = FileSystem.open("/mnt/sd/arduino/aleatoire.txt", FILE_READ);
  if(monFichier2) {
    Serial.println("--- Fichier ouvert");
    char c = 0;               //variable de lecture
    while (c != -1) {
      c = monFichier2.read();    //on lit un caractère
      Serial.print(c);          //affichage sur le moniteur
    }  
  }
  else {  
    Serial.println("Erreur de fichier");
    return; //stoppe le programme  
  }
    monFichier.close();
    Serial.println("--- Fichier clos");

}

void loop() {
}
