
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <Console.h>

YunServer server;
YunClient client;



void setup() {
  // Bridge startup
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(13, HIGH);
  Bridge.begin();
  Console.begin();//for debugging purposes
  

  // Listen for incoming connection from anywhere  
  server.noListenOnLocalhost();
  server.begin();  
}

void loop() {
  // Get clients coming from server
  YunClient client = server.accept();  
  
  //Is there a new client?  
  
  if (client) {    
    // Process request
    process(client);
    // Close connection and free resources.
    client.stop();
    }

  delay(50); // Poll every 50ms
}


void process(YunClient client) {
  // read the command  
  String command = client.readStringUntil('/');
  command.trim();
 
 if (command == "led13on") {
       digitalWrite(13, HIGH);              
    }
    else if (command == "led13off") {
       digitalWrite(13, LOW);
    }

}
