/* https://www.hackster.io/matlo/yunserver-sensor-values-to-html-page-4ca9b6 */
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 
#include<Console.h>
YunServer server;

void setup() {
  delay(5000);
  Bridge.begin();
  
  Console.begin();
  while ( !Console ) 
  {        
    ; //Attendre la connexion du port Console.
  }
  Console.println("Vous êtes connecté sur la Console !");  
  server.listenOnLocalhost();
  server.begin();
}

void loop() {
  YunClient client = server.accept();
  
  if (client) {
    Console.println("Client en ligne\n"); //on le dit...
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
