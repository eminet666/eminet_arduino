boolean affichage; //variable pour stopper l'affichage
int numPin;

void setup() {
    numPin=13;
    pinMode(numPin,OUTPUT);
    Serial.begin(9600);
    affichage=true; //initialisation de la variable à true
    Serial.println("*** Debut du programme ***");
}

void loop() {
    if (affichage) { // test si affichage vaut true
        //boucle de comptage
        for (int compteur=1;compteur<=20;compteur=compteur+1) {
            Serial.println(compteur);
            
            //boucle de clignotement : compteur sert de limite à la boucle
            for (int nbClignote=0;nbClignote<compteur;nbClignote=nbClignote+1) {
                digitalWrite(numPin,HIGH); //allume
                delay(250);
                digitalWrite(numPin,LOW); //eteind
                delay(250);
            }
            delay(1000); //attente de 1s
        }
        affichage=false; // on passe affichage à false
        Serial.println("*** fini ! ***");
    }
}
