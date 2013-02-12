const int ledPinYellow = 5; //digital input yellow LED is connected to 
const int ledPinRed = 4; //digital input red LED is connected to
const int sensorPin = 0; //analog input for potentiometer 

void setup(){ 
  Serial.begin (9600); 
  pinMode(ledPinYellow, OUTPUT); //initiate yellow LED as output 
  pinMode(ledPinRed, OUTPUT); //initiate red LED as output
} 

void loop(){ 
  int val; 
  int percent; 
  val = analogRead(sensorPin); 
  
  percent = map(val,0,1023,0,100); //map values from 0 to 100
  delay(percent);
  delay(100 - percent); 
  
  if (percent >= 25 && percent < 50){ 
    //statement to turn on ONLY yellow light
    digitalWrite(ledPinYellow, HIGH); 
    digitalWrite(ledPinRed, LOW);
  }else if (percent >= 50){  
    //statement to turn on red light 
    digitalWrite(ledPinYellow, HIGH);
    digitalWrite(ledPinRed, HIGH);
  }else{
    //otherwise, both lights should be off
    analogWrite(ledPinYellow, LOW); 
    digitalWrite(ledPinRed, LOW);
    
  }
  Serial.println(percent);
} 

