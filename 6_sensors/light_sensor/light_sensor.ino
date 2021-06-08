// source : https://tutorial45.com/arduino-light-sensor-project/
// sensor : https://osoyoo.com/2017/05/05/light-sensor/
void setup()
{
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
    Serial.println(analogRead(A0));
    delay(100);
    if (analogRead(A0) < 650)
    {
        digitalWrite(6, HIGH);
    }
    else
    {
        digitalWrite(6, LOW);
    }
}
