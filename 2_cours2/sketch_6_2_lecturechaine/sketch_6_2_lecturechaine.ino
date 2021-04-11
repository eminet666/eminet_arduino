char mot[]="Arduino"; // on initialise la chaîne de caractères

void setup() {
  delay(5000);
  Serial.begin(9600); // début communication série
  Serial.println(); // on saute une ligne
  int l=0; // variable de position dans la chaîne de caractère
  while (mot[l]){ // tant que la lettre n'est pas le caractère NULL
    Serial.print(mot[l]); // on écrit la lettre
    Serial.print(','); // on écrit une virgule
    l++; // on avance d'une position dans la chaîne
  }
}

void loop() {
  
}
