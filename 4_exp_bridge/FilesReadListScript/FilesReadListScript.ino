/*
  SD card datalogger

 The circuit:
 * analog sensors on analog pins 0, 1 and 2
 * SD card attached to SD card slot of the YunShield/Yún

 Prepare your SD card creating an empty folder in the SD root
 named "arduino". This will ensure that the Yún will create a link
 to the SD to the "/mnt/sd" path.

 You can remove the SD card while the Linux and the
 sketch are running but be careful not to remove it while
 the system is writing to it.
 */
#include <FileIO.h>
#include <Process.h>
#include <HttpClient.h>

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);
  FileSystem.begin();
  Process p;
  HttpClient client;

  while (!SerialUSB); // wait for Serial port to connect.
  SerialUSB.println("Filesystem datalogger\n");

  p.runShellCommand("rm /mnt/sd/datalog.txt");
  
  // 10 times
  for (int i = 0; i < 10; i++) {
      // make a string that start with a timestamp for assembling the data to log:
      String dataString;
      dataString += getTimeStamp();
      dataString += " = ";
    
      // read three sensors and append to the string:
      for (int analogPin = 0; analogPin < 3; analogPin++) {
        int sensor = analogRead(analogPin);
        dataString += String(sensor);
        if (analogPin < 2) {
          dataString += ",";  // separate the values with a comma
        }
      }
    
      // open the file. note that only one file can be open at a time,
      File dataFile = FileSystem.open("/mnt/sd/datalog.txt", FILE_APPEND);
    
      // if the file is available, write to it:
      if (dataFile) {
        dataFile.println(dataString);
        dataFile.close();
        // print to the serial port too:
        SerialUSB.println(dataString);
      }
      // if the file isn't open, pop up an error:
      else {
        SerialUSB.println("error opening datalog.txt");
      }
    
      delay(5000);
  }

  SerialUSB.println("--- affichage du fichier /mnt/sd/datalog.txt ---");
  p.runShellCommand("cat /mnt/sd/datalog.txt");
  while (p.available()) {
    char c = p.read();
    SerialUSB.print(c);
  }

}


void loop() {

}

// This function return a string with the time stamp
String getTimeStamp() {
  String result;
  Process time;
  // date is a command line utility to get the date and the time
  // in different formats depending on the additional parameter
  time.begin("date");
  time.addParameter("+%D-%T");  // parameters: D for the complete date mm/dd/yy
  //             T for the time hh:mm:ss
  time.run();  // run the command

  // read the output of the command
  while (time.available() > 0) {
    char c = time.read();
    if (c != '\n') {
      result += c;
    }
  }

  return result;
}
