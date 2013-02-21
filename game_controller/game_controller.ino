const int rightLEDPin = 4; 
const int leftLEDPin = 5; 
const int upLEDPin = 1; 
const int downLEDPin = 2; 
const int UpDownPin = 0; 
const int rightPin = 1; 
const int leftPin = 2; 

void setup(){
 Serial.begin(9600); 
 pinMode(rightLEDPin, OUTPUT);
 pinMode(leftLEDPin, OUTPUT); 
 pinMode(upLEDPin, OUTPUT);
 pinMode(downLEDPin, OUTPUT);
} 

void loop(){ 
  int valDial; 
  int valLeft; 
  int valRight;
  int percent;
  
  valDial = analogRead(UpDownPin); 
  valLeft = analogRead(leftPin); 
  valRight = analogRead(rightPin);
  
  percent = map(valDial,0,1023,0,100); //map values from 0 to 100
  delay(percent);
  delay(100 - percent); 
  
  if (percent >= 25 && percent < 50){ 
    //statement to turn on ONLY yellow light
    digitalWrite(upLEDPin, HIGH); 
    digitalWrite(downLEDPin, LOW);
  }else if (percent >= 50){  
    //statement to turn on red light 
    digitalWrite(upLEDPin, HIGH);
    digitalWrite(downLEDPin, HIGH);
  }else{
    //otherwise, both lights should be off
    analogWrite(upLEDPin, LOW); 
    digitalWrite(downLEDPin, LOW); 
  }
  
  if (valLeft == HIGH){ 
    digitalWrite(leftLEDPin, HIGH);
    Serial.println("Left on!");
  }else{ 
    digitalWrite(leftLEDPin, LOW); 
  } 
  
  if (valRight == HIGH){ 
    digitalWrite(rightLEDPin, HIGH); 
  }else{ 
    digitalWrite(rightLEDPin, LOW); 
  }
  
  //Serial.println(percent);
} 

