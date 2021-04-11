// à tester sur COM série
#include <FileIO.h>
 
void setup() {
     
    Bridge.begin();
     
    Serial.begin(9600);
    while(!Serial);
     
    Serial.println("File write example");
     
    if (!FileSystem.begin()) {
        Serial.println("Init Failed !");
    }
     
    File file = FileSystem.open("/mnt/sda1/test.txt", FILE_WRITE);
     
    if (!file) {
        Serial.println("Open Failed !");
    }
     
    file.print("test!");
    file.close();
     
}

void loop() {
  
}
