const int lightPin = 0; 
const int humidPin = 1; 
const int tempPin = 2; 

float rawTemp = 0; //raw Temperature values 
float vTemp = 0; //voltage values
float celTemp = 0; //Celsius values 

float light = 0;
float otherLight = 0; 

void setup(){ 
  Serial.begin(9600); 
} 

void loop(){ 
  rawTemp = analogRead(tempPin); //reading the Temp pin 
  light = analogRead(lightPin);
  
  float relativeHumidity  = getHumidity(celTemp);
  
  //Serial.print("Raw light Val:"); 
  Serial.print(light);
  Serial.print(",");
  //Serial.println(".");
  //print Raw A/DC values
  //Serial.print("Raw ADC Val: "); 
  //Serial.println(rawTemp);  

  vTemp = (rawTemp*5)/1024;  //convert ADC vals to volts
  
  //print volt values 
  //Serial.print(vTemp); 
  //Serial.println(" Volts");  
  
  celTemp = (vTemp - 0.5)*100; //convert volt values to Celsius
  
  //print Celsius measurements
  //Serial.print("Temp ="); 
  Serial.print(celTemp);
  Serial.print(","); 
  //Serial.println(" C");
  
  //Serial.print("Rel. Humidity ="); 
  Serial.println(relativeHumidity);  
  //Serial.println(" "); 
  delay(1000); 
  
} 

float getHumidity(float celTemp){
  //caculate relative humidity
  float supplyVolt = 5.0;

  // read the value from the sensor:
  int humidValue = analogRead(humidPin);
  float voltage = humidValue/1023. * supplyVolt; // convert to voltage value

  // convert the voltage to a relative humidity
  // - the equation is derived from the HIH-4030/31 datasheet
  // - it is not calibrated to your individual sensor
  //  Table 2 of the sheet shows the may deviate from this line
  float sensorRH = 161.0 * voltage / supplyVolt - 25.8;
  float trueRH = sensorRH / (1.0546 - 0.0026 * celTemp); //temperature adjustment 

  return trueRH;
}
