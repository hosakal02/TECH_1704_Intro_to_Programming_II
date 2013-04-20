import processing.serial.*;

PrintWriter OUTPUT; 
//float sensorVal = 0.0; 
int sensorVal[]; 
float rawSensorVal = 0.0;

Serial port;

void setup(){ 
 size(100,100);
 background(0);  
 
 //list all serial values
 println(Serial.list()); 
 //new serial object
 port = new Serial (this, Serial.list()[0], 9600);  
 
 port.bufferUntil('\n'); 
 
 OUTPUT = createWriter("environData.txt");
} 

void draw(){
 convert(); 
} 

void keyPressed(){
  /*if(key == 'c'){ 
    convert();
   }*/
  if(key == 'e'){  
      exportText(); 
  }
}

void serialEvent(Serial port) {
  //println("Serial Event Begun");

  String myString = port.readStringUntil('\n');    //read serial buffer until you hit a new line character
  //println("String Declared and port read");

  if (myString != null) {  //check to make sure string is not = null 

      println(myString);  //printing out the raw values incoming

      myString = trim(myString);    //remove whitespace

      /*sensorVal[] = int(split(myString, ','));  //split the string by commas and cast as ints into int array

      for (int i = 0; i < sensorVal.length; i++) {      //print out the values with their sensor names
        print("SensorVal "+i+": "+sensorVal[i]+"\t");
      */
      rawSensorVal = float(myString);
      
    }
      //println(); 
  } 
  
void processRawSerial(){ 
  sensorVal[] = float(split(rawSensorVal, ','));  //split the string by commas and cast as ints into int array
}

void convert(){ 
   OUTPUT.println(sensorVal);
   OUTPUT.flush(); 
   //println("Starting write to text");
}

void exportText(){ 
  OUTPUT.close(); 
  super.stop();
  println("data exported"); 
} 
      
