#include <math.h>
double Thermister(int RawADC) {
    double Temp;
    Temp = log(((10240000/RawADC) - 1000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.000000087641 * Temp * Temp)) * Temp );
    Temp = Temp -273.15;
    return Temp;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(Thermister(analogRead(0)));
}
