void setup() {
  Serial.begin(9600); // initialisation de la communication
}

void loop() {
  while (Serial.available()) { // tant que des caractères sont en attente
    char c = Serial.read(); // on lit le caractère
    Serial.print(c); // on l'affiche
    Serial.print('\t'); // on affiche une tabulation
    Serial.println(int(c)); //on affiche le code correspondant
    delay(10); //petit temps de pause
  }
}
