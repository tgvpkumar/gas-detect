#include <SoftwareSerial.h>

SoftwareSerial sgsm(2, 3); // RX, TX

#define redLED 12 // red led is connected to Arduino pin 12
#define greenLED 13 // green led is connected to Arduino pin 13
#define Buzzer 10 // Buzzer red wire is connected to Arduino pin 9 
#define gasSensor A0 // MQ5 Sensor is connected to Arduino pin A0 

#define Thresholdvalue 400 // threshold value 

void setup(){
  Serial.begin(9600);
  sgsm.begin(9600);
  
  pinMode(redLED,OUTPUT);
  digitalWrite(redLED,HIGH);
  
  pinMode(greenLED,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  
  digitalWrite(greenLED,HIGH);
  digitalWrite(Buzzer,HIGH);
  delay(500);
  digitalWrite(greenLED,LOW);
  digitalWrite(Buzzer,LOW);

  sendmessage();
}

float gasdetect(){
  float gas_value;
  gas_value = analogRead(gasSensor);
  Serial.print("Sensor Value:");
  Serial.println(gas_value);
  
  return gas_value;
} 

void sendmessage(){
  sgsm.print("\r");
  delay(1000);
  sgsm.print("AT+CMGF=1\r");
  delay(1000);
  sgsm.print("AT+CMGS=\"+919963426572\"\r");
  delay(1000); 
  sgsm.println("System is switched on, Gas is not detected");
  delay(1000);
  sgsm.write(0x1A);
  delay(1000);

  Serial.println("Message sent");
}

void message(){
  sgsm.print("\r");
  delay(1000);
  sgsm.print("AT+CMGF=1\r");
  delay(1000);
  sgsm.print("AT+CMGS=\"+919963426572\"\r");
  delay(1000);
  sgsm.println("Gas is detected");
  delay(1000);
  sgsm.write(0x1A);
  delay(1000);
  
  Serial.println("Message sent");
}
 
void loop(){
  if(gasdetect() > Thresholdvalue){
    digitalWrite(greenLED,HIGH);
    tone(Buzzer, 1000, 200);
    digitalWrite(Buzzer,HIGH);
    message();
    
    Serial.println(" here sensor value is < threshold value So LED is On, Buzzer is On");
  }
  else{
    digitalWrite(greenLED, LOW);
    noTone(Buzzer);
    
    Serial.println(" here sensor value is > threshold value So LED is Off, Buzzer is Off");
  }
  delay(100);
}
