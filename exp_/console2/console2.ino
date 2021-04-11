/* http://projet.eu.org/pedago/sin/tutos/arduino_yun.pdf */
#include<Console.h>
const int ledPin = 13; 
// La broche sur laquelle la LED est branchée

void setup(){
  // Initialisation de la communication série:    
  Bridge.begin();    
  Console.begin();
  
  while ( !Console ) 
  {        
    ; //Attendre la connexion du port Console.
  }
  Console.println("Vous êtes connecté sur la Console !");
  
  // Initialiser la broche de la LED comme sortie:    
  pinMode(ledPin, OUTPUT);
}

void loop(){
  // Vérifier s'il y a une donnée entrante:
  if ( Console.available() > 0 ) 
  {
    // Lire le byte (l'octet) le plus vieux stocké dans
    // la mémoire tampon série (serial buffer):
    switch ( Console.read() ) 
    {
       // Si c'est un H majuscule (ASCII 72), allumer la LED:
      case'H': digitalWrite(ledPin, HIGH);break;
      // Si c'est un L (ASCII 76), éteindre la LED:
      case'L': digitalWrite(ledPin, LOW);break;
      default: break;
     }
   }
}
