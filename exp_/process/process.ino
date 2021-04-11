/* http://projet.eu.org/pedago/sin/tutos/arduino_yun.pdf */
#include<Process.h>

void setup(){
  delay(5000);
  // Initialisation du Bridge  
  Bridge.begin();
  // Initialisation du port série  
  Serial.begin(9600);
  
  Serial.println("Communication série init...");
  // Attendre qu'un moniteur série soit connecté.
  while ( !Serial );
  Serial.println("Communication série OK");
  
  // Exécuter les différents processus d'exemple  
  runCurl();
}
void loop(){
  // Rien à faire.
}

void runCurl(){
  // Execute la commande "curl" et obtenir un logo Arduino en "ascii art" depuis le Net
  // curl est un programme en ligne de commande pour transférer des données en utilisant
  //    différents protocols Internet  
  Process p;        // Créer un processus et appellons le "p"  
  p.begin("curl");  // Processus qui démarre la commande "curl"  
  p.addParameter("http://arduino.cc/asciilogo.txt"); // Ajouter le parametre URL à "curl"  
  p.run();          // Exécuter le processus et attendre sa fin d'exécution
  
  // Afficher le logo Arduino sur le port série
  // La sortie d'un processus (''process output'') peut être lut à laide
  // des méthodes de streaming (gestion de flux)
  while ( p.available() > 0 ) 
  {
    char c = p.read();    
    Serial.print(c);   
  }
  
  // S'assurer que les derniers bits de données soit bien envoyés  
  Serial.flush();
}
