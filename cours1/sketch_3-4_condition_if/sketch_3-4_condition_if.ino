int affichageFait;// déclaration de la variable
int index = 0;

void setup(){
    Serial.begin(9600);
    affichageFait=0;//initialisation de la variable
}

void loop(){
    delay(1000);
    if (affichageFait==0){    // exécuté que si la condition est vérifiée
        Serial.print(index);
        Serial.print(" Hello");
        Serial.print(" Arduino");
        Serial.println("World !");
        //affichageFait=1;      //on passe la variable à 1 pour ne plus exécuter le code
        index++;
    }
}
