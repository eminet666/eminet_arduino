/* https://www.arduino.cc/en/Tutorial/LibraryExamples/TemperatureWebPanel */
#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>

        BridgeServer server;
String startString;
long hits = 0;

void setup() {
  SerialUSB.begin(9600);

  // Bridge startup
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  // using A0 and A2 as vcc and gnd for the TMP36 sensor:
  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);

  // Listen for incoming connection only from localhost
  server.listenOnLocalhost();
  server.begin();

  // get the time that this sketch started:
  Process startTime;
  startTime.runShellCommand("date");
  while (startTime.available()) {
    char c = startTime.read();
    startString += c;
  }
}

void loop() {
  // Get clients coming from server
  BridgeClient client = server.accept();

  // There is a new client?
  if (client) {
    // read the command
    String command = client.readString();
    command.trim();        //kill whitespace
    SerialUSB.println(command);
    // is "temperature" command?
    if (command == "temperature") {

      // get the time from the server:
      Process time;
      time.runShellCommand("date");
      String timeString = "";
      while (time.available()) {
        char c = time.read();
        timeString += c;
      }
      SerialUSB.println(timeString);
      int sensorValue = analogRead(A1);
      // convert the reading to millivolts:
      float voltage = sensorValue * (5000.0f / 1024.0f);
      // convert the millivolts to temperature celsius:
      float temperature = (voltage - 500.0f) / 10.0f;
      // print the temperature:
      client.print("Current time on the Y&uacute;n: ");
      client.println(timeString);
      client.print("<br>Current temperature: ");
      client.print(temperature);
      client.print(" &deg;C");
      client.print("<br>This sketch has been running since ");
      client.print(startString);
      client.print("<br>Hits so far: ");
      client.print(hits);
    }

    // Close connection and free resources.
    client.stop();
    hits++;
  }

  delay(50); // Poll every 50ms
}
