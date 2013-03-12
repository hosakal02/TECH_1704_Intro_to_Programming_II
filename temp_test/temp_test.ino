const int tempPin = 0; //Temperature sensor pin
const int heatPin = 2; //heat LED pin
const int coldPin = 3; //cold LED pin

float rawTemp = 0; //raw Temperature values 
float vTemp = 0; //voltage values
float celTemp = 0; //Celsius values 

void setup(){
 Serial.begin(9600); 
 pinMode(heatPin, OUTPUT); 
 pinMode(coldPin, OUTPUT); 
} 

void loop(){ 
  float heatVal; 
  float coldVal;
  
  rawTemp = analogRead(tempPin); //reading the Temp pin 
  heatVal = digitalRead(heatPin); //reading the Heat pin
  coldVal = digitalRead(coldPin); //reading the Cold pin
  
  //print Raw A/DC values
  Serial.print("Raw ADC Val: "); 
  Serial.println(rawTemp);  

  vTemp = (rawTemp*5)/1024;  //convert ADC vals to volts
  
  //print volt values 
  Serial.print(vTemp); 
  Serial.println(" Volts"); 
  
  celTemp = (vTemp - 0.5)*100; //convert volt values to Celsius
  
  //print Celsius measurements
  Serial.print("Temp ="); 
  Serial.print(celTemp); 
  Serial.println(" C");
  
  delay(1000); 
  
  //Switch lights on
  if (celTemp >= 65.0){
    //switch on Heat LED if higher than 65.0 C 
    digitalWrite(heatPin, HIGH); 
    digitalWrite(coldPin, LOW); 
  }else if (celTemp <= 64.0){ 
    //switch on Cold LED if lower than 64.0 C
    digitalWrite(heatPin, LOW); 
    digitalWrite(coldPin, HIGH); 
  }else{ 
    //both are off
    digitalWrite(heatPin, LOW); 
    digitalWrite(coldPin, LOW);
  }
}
