#include <FileIO.h>
#include <Process.h>

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);
  FileSystem.begin();
  Process p;

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
    
      delay(1000);
  }
  
}

void loop() {
  SerialUSB.flush();

  while (!SerialUSB.available());

    String cmd = readStringUntilNewLine();
  
    SerialUSB.println(cmd);
    if (cmd == "bye") {
      SerialUSB.println(F("\nGoodbye"));
      halt();
    }
    else actions(cmd);

}

void halt() {
  SerialUSB.flush();
  while (true);
}

void actions(String cmd) {
    Process p;
    SerialUSB.println("--- commande : "+cmd+" ---");
    // p.runShellCommand("cat /mnt/sd/datalog.txt");
    p.runShellCommand(cmd);
    while (p.available()) {
      char c = p.read();
      SerialUSB.print(c);
    }
}

String readStringUntilNewLine() {
  String s = Serial.readStringUntil('\n');
  if (s.length() > 1 && s.charAt(s.length() - 1) == '\r') {
    s.setCharAt(s.length() - 1, '\0');
  }
  return s;
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
