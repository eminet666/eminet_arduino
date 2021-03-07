const int CONNEXION=13;

void setup() { 
    pinMode(CONNEXION,OUTPUT);
}
void loop() {
    digitalWrite(CONNEXION,HIGH);
    delay(1000);
    digitalWrite(CONNEXION,LOW);
    delay(1000);
}
