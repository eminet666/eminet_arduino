void setup() {
  Serial.begin(9600); //début de la communication série
}

void loop() {
  while (Serial.available()) { // tant que caractères en attente d'être lus
    char c = Serial.read(); // on lit le charactère
    Serial.print(c); // on l'écrit sur le moniteur
    delay(10); // petit temps de pause
  }
}
