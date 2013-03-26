#include <Servo.h> //import servo library 

const int rightPin = 2; //right button 
const int leftPin = 8; //left button
const int bluLEDPin = 9; //blue led 
const int redLEDPin = 10; //red led
const int greenLEDPin = 11; //green led

Servo myservo; //servo object

int angle = 0; //angle variable

void setup(){ 
 myservo.attach(7);
 
 pinMode(rightPin, INPUT); 
 pinMode(leftPin, INPUT); 
 pinMode(bluLEDPin, OUTPUT); 
 pinMode(redLEDPin, OUTPUT); 
 pinMode(greenLEDPin, OUTPUT);
  //Serial.begin(9600);
} 

void loop(){ 
  //read button pins
  int rightVal = digitalRead(rightPin); 
  int leftVal = digitalRead(leftPin); 
 //read LED pins 
  int bluVal = digitalRead(bluLEDPin); 
  int redVal = digitalRead(redLEDPin); 
  int greenVal = digitalRead(greenLEDPin); 
  
  if (rightVal == HIGH){
    //moves servo rotor to 180 position
      angle = 180; 
      myservo.write(angle); 
      delay(10); 
      //turns on blue LED
       digitalWrite(bluLEDPin, HIGH); 
       digitalWrite(redLEDPin, LOW); 
       digitalWrite(greenLEDPin, LOW);
    }else if (rightVal == LOW){ 
     //servo motor goes idle to 90 position
     angle = 90; 
     myservo.write(angle); 
     delay(10); 
     //turns on green LED
      digitalWrite(bluLEDPin, LOW); 
      digitalWrite(redLEDPin, LOW); 
      digitalWrite(greenLEDPin, HIGH);
  } 
 
 if (leftVal == HIGH){ 
  //turns servo motor to 0 position
    angle = 0; 
    myservo.write(angle); 
    delay(10); 
    //turns on red light
     digitalWrite(bluLEDPin, LOW); 
     digitalWrite(redLEDPin, HIGH); 
     digitalWrite(greenLEDPin, LOW);
   }else if (leftVal == LOW){ 
    //moves to idle position of 90
    angle = 90; 
    myservo.write(angle); 
    delay(10);
    //turns on green light
     digitalWrite(bluLEDPin, LOW); 
     digitalWrite(redLEDPin, LOW); 
     digitalWrite(greenLEDPin, HIGH);

   }
 }
//}
