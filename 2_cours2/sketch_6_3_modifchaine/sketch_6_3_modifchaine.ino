char mot[]="Jean de la Fontaine"; // une chaîne de caractère avec des espaces

void setup() {
  delay(5000);
  Serial.begin(9600); // on initialise la communication série
  Serial.println(); // on saute une ligne
  int l=0; // variable pour parcourir la chaîne
  while (mot[l]){ // tant qu'on n'est pas au bout de la chaîne (caractère NULL)
    if (mot[l]==' ') // on teste si le caractère est un espace
      mot[l]='-'; // si oui, on le remplace par un tiret
    l++; // on passe au caractère suivant
  }
  Serial.println(mot); // on écrit la chaîne résultante
}

void loop() {
  
} 
