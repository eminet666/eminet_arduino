/* https://temboo.com/arduino/yun/serial-to-console */
#include <Bridge.h>

void setup() {
    delay(5000);
    Bridge.begin();

// sur port COM
//    Serial.begin(9600);
//    while (!Serial); // wait for Serial port to connect.
//    Serial.println("Communication Série 0K\n");

// sur adresse ip
    Console.begin();
    while(!Console); // wait for internet port to connect.
    Console.println("Communication Console 0K\n");      

}

void loop(){

}
