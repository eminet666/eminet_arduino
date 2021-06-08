// source : https://osoyoo.com/2017/05/05/arduino-light-sensor-tutorial/
// sensor : https://osoyoo.com/2017/05/05/light-sensor/
void setup()
{
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(9, OUTPUT);
}

void loop()
{
    Serial.println(analogRead(A0));
    delay(100);
    if (analogRead(A0) < 100)
    {
        digitalWrite(9, HIGH);
    }
    else
    {
        digitalWrite(9, LOW);
    }
}
