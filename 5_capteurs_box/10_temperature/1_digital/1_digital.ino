/* https://www.gotronic.fr/pj2-mf52type-1554.pdf */
#include <math.h>
double Thermister(int RawADC) {
    double Temp;
    Temp = log(((10240000/RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp );
    Temp = Temp -273.15;
    return Temp;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(Thermister(analogRead(0)));
  Serial.println("C");
  delay(1000);
}
