int  pinLed[3] = {2, 4, 6}; //déclaration et initialisation du tableau
void setup(){
  //Boucle d'initialisation des modes et mise à 0V
  for (int i = 0; i < 3; i++){
    pinMode(pinLed[i], OUTPUT); //on utilise les valeurs du tableau
    digitalWrite(pinLed[i], LOW); // l'une après l'autre
  }
}
void loop(){
  //on allume les 3 LED (ici en utilisant une boucle)
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinLed[i], HIGH);// on allume chaque led
  }
  delay(1000); //pendant 1 seconde
  //puis on les éteint brièvement
  digitalWrite(pinLed[0],LOW); // on éteint la 1
  digitalWrite(pinLed[1], LOW); // on éteint la 2
  digitalWrite(pinLed[2],LOW); // on éteint la 3
  delay(100);//délai bref
  
  //Boucle pour diminuer le temps d’allumage des LED
  for (int temps = 1000; temps >= 200; temps -= 200) {
    //Les trois LED sont éteintes
    for (int i = 0; i < 3; i++) { 
      // t pour parcourir le tableau
      digitalWrite(pinLed[i], HIGH);//on allume la LED correspondante
      delay(temps); // pendant la valeur de temps
      digitalWrite(pinLed[i], LOW); //on éteint la correspondante
      delay(100); // court délai pendant lequel les 3 LED sont éteintes
    }
    // 3 LED allumées pendant une durée “temps”, boucle reprend décrémentée
  }
}
