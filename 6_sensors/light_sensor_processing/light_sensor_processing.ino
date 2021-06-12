// source : https://create.arduino.cc/projecthub/sowmith/visualising-sensor-data-using-arduino-and-processing-e707f0?ref=tag&ref_id=processing&offset=3
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
    if (analogRead(A0) < 300)
    {
        digitalWrite(9, HIGH);
    }
    else
    {
        digitalWrite(9, LOW);
    }
}
