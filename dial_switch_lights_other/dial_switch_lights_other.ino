const int ledPinYellow = 5; //digital input yellow LED is connected to 
const int ledPinRed = 4; //digital input red LED is connected to
const int sensorPin = 0; //analog input for potentiometer 

void setup(){ 
  Serial.begin (9600); 
  pinMode(ledPinYellow, OUTPUT); 
  pinMode(ledPinRed, OUTPUT); 
  pinMode(sensorPin, INPUT); 
} 

void loop(){ 
  int val; 
  int percent; 
  val = analogRead(sensorPin); 
  
  percent = map(val,0,1023,0,100); 
  //digitalWrite(ledPin, HIGH); 
  delay(percent); 
  //digitalWrite(ledPin, LOW); 
  delay(100 - percent); 
  
  if (percent <= 25){ 
    analogWrite(ledPinYellow, HIGH);
    //delay(percent);  
  }else if (percent <= 75){  
    digitalWrite(ledPinRed, HIGH);
   // delay(100-percent); 
  }else{
    analogWrite(ledPinYellow, LOW); 
    digitalWrite(ledPinRed, LOW);
    
  }
  Serial.println(percent);
} 

