int pinLed[5]={2,4,6,8,10}; // Tableau listant les pins
//tableau états (booléen 1 allumé, 0 éteint) des LED à chaque séquence
boolean affichage[25][5]={
  0,0,0,0,0,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,0,0,
  0,1,0,0,0,
  1,0,0,0,0,
  0,0,0,0,0,
  1,0,0,0,0,
  0,1,0,0,0,
  0,0,1,0,0,
  0,0,0,1,0,
  0,0,0,0,1,
  0,0,0,0,0,
  1,1,1,1,1,
  1,1,1,1,0,
  1,1,1,0,0,
  1,1,0,0,0,
  1,0,0,0,0,
  0,0,0,0,0,
  1,1,1,1,1,
  0,1,1,1,1,
  0,0,1,1,1,
  0,0,0,1,1,
  0,0,0,0,1,
  0,0,0,0,0};

void setup() {
  for (int i=0;i<5;i++)
  {
    pinMode(pinLed[i],OUTPUT);
    digitalWrite(pinLed[i],LOW);
  }
  
}

void loop() {
  for (int i=0;i<25;i++) // boucle de séquence d'affichage
  {
    for (int p=0;p<5;p++) // boucle pour chaque pin
    {
      boolean etat=affichage[i][p]; // on va chercher l'état pour le pin
      digitalWrite(pinLed[p],etat); // on met le pin concerné à l'état
    }
    //tous les pins sont dans l'état de la séquence en cours
    delay(300); //petite pause d'affichage
    // on passe à la séquence suivante
  }
  // fin des séquences et on repart au début de la loop()

}
