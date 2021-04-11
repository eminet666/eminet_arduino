#include <Bridge.h>
#include <FileIO.h>
boolean messageOK = 1;

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);

  delay(5000);
  Serial.println("--- Initialisation...");
  while (!Serial); // wait for Serial port to connect.
  Serial.println("--- Communication série OK !");

  // Setup File IO
  if(!FileSystem.begin()){
    Serial.println("ERREUR FileSystem Failed !");
    return;
  }
  else {
     Serial.println("--- FileSystem OK !");
  }

}

void loop() {
  if (Serial.available()) {     //teste s'il y a une saisie en attente
    analyse(); //lance l'analyse de la saisie
  }
}

//---------------------------* fonctions* ----------------------

//fonction d'analyse de la saisie
void analyse() {
  String chaine = "";                   // création d'un String vide
  
  //lecture de la saisie
  while (Serial.available()) {          //tant que caractères en attente.
    delay(10);                          //petit délai de lecture
    char c = Serial.read();             //on lit le message
    
    //empêche la saisie d'un #
    if (c == '#') {
      Serial.println("<!> ne pas saisir de #, merci");
      chaine = "";                      //on vide la chaine
      while (Serial.available())        //on vide la saisie
        Serial.read();
      return;                           //on retourne au programme
    }
    if (c != 10 && c != 13) {           //nettoyage de la chaine
      chaine += c;                      //on ajoute le caractère
    }
  }
  
  //test de la saisie
  if (chaine == "liste") {              //si liste demandée
    lister();
    return;
  }
  else if (chaine == "efface") {        //si effacement demandé
    effacer();
    return;
  }
  else if (chaine == "compte") {        // si comptage demandé
    compter();
    return;
  }

  //si aucun code spécial
  ajouter(chaine); // ajout d'un item

}

//fonction d'affichage de la liste
void lister() {
  message("lister");
  File monFichier = FileSystem.open("/mnt/sd/arduino/liste.txt", FILE_READ);
  if (monFichier) {                             //appelle la fonction pour ouvrir
    Serial.println("* liste *");
    char c = 0;                                 //variable de lecture
    int pos = 2;                                //position dans la chaîne de caractère
    char tab[102] = {0};                        //tableau de la chaîne de caractère
    tab[0] = '-';                               //mise en page
    tab[1] = ' ';                               //avec un tiret
    while (c != -1) {
      delay(10);
      c = monFichier.read();                    //on lit un caractère
      if (c == '#') {                           //si # on affiche
        tab[pos] = '\0';                        //ajout du caractère de fin de chaîne
        Serial.println(tab);                    //affichage sur le moniteur
        pos = 2;                                //remise à zéro de la position
      }
      else {                                    // sinon
        tab[pos] = c;                           //on ajoute le caractère à la chaîne
        pos++;                                  //on incrémente le curseur dans la chaîne
      }
    }
    monFichier.close();                         //on ferme le fichier
    message("Fichier clos");
    return;
  }
  else Serial.println("ERREUR Fichier inaccessible");
}

//fonction d'effacement de la liste
void effacer() {
  message("Effacement de la liste");
  message("Teste si fichier existant");
  if(FileSystem.exists("/mnt/sd/arduino/liste.txt")){
    message("Destruction fichier");
    FileSystem.remove("/mnt/sd/arduino/liste.txt");
    Serial.println("Effacement OK");
    return;
  }
  message("Fichier inexistant");
}

//fonction de comptage des items
void compter() {
  message("compter");
  File monFichier = FileSystem.open("/mnt/sd/arduino/liste.txt", FILE_WRITE);
  if (monFichier) {
    Serial.print("La liste comporte ");
    int nb = 0;
    char c;
    while (c != -1) {
      c = monFichier.read();                          //on lit un caractère
      if (c == '#') {
        nb++;
      }
    }
    Serial.print (nb);
    Serial.print (" item");
    if (nb > 1) Serial.print("s");
    Serial.println();
    monFichier.close();                               //on ferme le fichier
    message("Fichier clos");
    return;
  }
  else Serial.println("ERREUR Fichier inaccessible");
}

//fonction d'ajout d'un Item
void ajouter(String item) {
  message ("Ajout de <" + item + ">");
  File monFichier = FileSystem.open("/mnt/sd/arduino/liste.txt", FILE_APPEND);
  if (monFichier) {
    message("Fichier ouvert");
    item.trim();
    monFichier.print(item);                             //écriture dans le fichier
    monFichier.write('#');
    monFichier.close();
    message("Fichier clos");
    Serial.println("Ajout de <" + item + "> fait");
    return;
  }
  else Serial.println("ERREUR Fichier inaccessible");
}

//fonction d'ouverture de fichier
boolean ouvrir(int mode) {
  message("Ouverture du fichier");
  if (mode) {
    File monFichier = FileSystem.open("/mnt/sd/arduino/aleatoire.txt", FILE_WRITE);
      if (!(monFichier)) {                                //tentative d'ouverture du fichier
    message("Erreur de fichier");
    return 0;
  } else {
    message("Fichier ouvert");
    return 1;
  }
  }
  else {
    File monFichier = FileSystem.open("/mnt/sd/arduino/aleatoire.txt", FILE_READ);
  }
  

}

//fonction d'affichage des messages
void message(String s) {
  if (messageOK) {
    Serial.println("\t>"+s);
  }
}
