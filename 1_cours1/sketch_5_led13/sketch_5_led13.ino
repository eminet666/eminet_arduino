int pinLed=13; 
void setup(){
    pinMode(pinLed,OUTPUT); }
void loop(){
    digitalWrite(pinLed,HIGH); // +5V
    delay (1000);
    digitalWrite(pinLed,LOW);  // 0V
    delay(1000);
}
