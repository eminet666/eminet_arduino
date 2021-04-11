int pinLed1, pinLed2, pinLed3; 
void setup(){
  //initialisation des variables
  pinLed1 = 2;
  pinLed2 = 4;
  pinLed3 = 6;
  //initialisation des modes
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  //mise à 0V de chaque pin
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
}
void loop(){
  //test allumage-repérage des lEDs
  digitalWrite(pinLed1, HIGH);
  delay(500);
  digitalWrite(pinLed2, HIGH);
  delay(500);
  digitalWrite(pinLed3, HIGH);
  delay(500);
  //on éteint tout
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  delay(500);
}
