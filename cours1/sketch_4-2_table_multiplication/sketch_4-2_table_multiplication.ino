int numTable; // variable pour la table concernée
boolean affiche; // variable d'affichage

void setup() {
  affiche = true; // initialisation à true
  numTable = 7; // iniialisation à 7
  Serial.begin(9600); //initialisation de l'affichage
  
  //Affichage de l'entête du programme
  Serial.println("***********************");
  Serial.println("Table de multiplication");
  Serial.print("La table de : "); //pas de retour à la ligne
  Serial.println(numTable); // affichage de la variable
  Serial.println(); // saut de ligne pour aérer
}

void loop() {
  delay(1000);
  if (affiche) { // test si vrai
    // boucle de progression pour la multiplication
    for (int t = 0; t < 15; t++) {
      int resultat = numTable * t; // variable pour stocker le résultat
      
      // Affichage de la ligne
      Serial.print(t);
      Serial.print(" x ");
      Serial.print(numTable);
      Serial.print(" = ");
      Serial.println(resultat); // ou Serial.println(numTable*t); pour ne pas créer résultat 
    }
    Serial.println(); // saut de ligne
    Serial.println("***********************");
    affiche=false; // passage à false pour ne plus afficher
  }
}
