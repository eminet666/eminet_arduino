/* source : https://www.hackster.io/matlo/yunserver-sensor-values-to-html-page-4ca9b6 */
/* accès  : http://192.168.0.33/sd/test_sensor_values */
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 
YunServer server;

void setup() {
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
}
void loop() {
  YunClient client = server.accept();
  if (client) {
    String command = client.readString();
    command.trim();
    if (command == "temperature") {
      int val = analogRead(A1);
      client.print(val);
    }
    client.stop();
  }
  delay(50);
}
