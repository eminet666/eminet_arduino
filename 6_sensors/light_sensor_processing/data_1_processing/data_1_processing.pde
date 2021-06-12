//import Serial communication library
import processing.serial.*;

//init variables
Serial myPort;
float light;
int n = 0;

void setup()
{
   size(600, 600);
   myPort = new Serial(this, "COM7", 9600); //init serial
}

void draw()
{
  while (myPort.available() > 0) {
    String inBuffer = trim(myPort.readString());   
    if (inBuffer != null) {
     // light = float(inBuffer);
     //println(n+" _ "+light);
      println(n+" _ "+float(inBuffer));
      n++;
      
      delay(1000);
    }
  }  
   
   //refresh the background to clear old data
   //textAlign(CENTER);
   //text(intensity, width/2, height/2); 

}
