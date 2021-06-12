// Example by Tom Igoe

import processing.serial.*;

Serial myPort;  // The serial port
float light;

void setup() {
  size(600,600);
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  // myPort = new Serial(this, Serial.list()[0], 9600);
  myPort = new Serial(this, "COM7", 9600);  
}

void draw() {
  while (myPort.available() > 0) {
    String inBuffer = trim(myPort.readString());   
    if (inBuffer != null) {
      light = float(inBuffer);
      println(light);
      
      background(111);
      noStroke();
      fill(255,0,0);
      circle(width/2, height/2, light/4);
      
      //refresh the background to clear old data
      fill(255);
      textAlign(CENTER);
      text(light, width/2, height/2); 
      
      
      
    }
  }
}
