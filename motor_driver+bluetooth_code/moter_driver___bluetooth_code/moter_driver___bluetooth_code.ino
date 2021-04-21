// Tutorial on Motor Control By Robo India
// Hardware used HC-05 and Motor Driver connected with motors

#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(2,3);    // (TXD, RXD) of HC-06
char BT_input;                    // to store input character received via BT.
int motorPin1 = 8;                // pin 2 on L293D IC
int motorPin2 = 9;                // pin 7 on L293D IC
int motorPin3 = 10;               // pin 15 on L293D IC
int motorPin4 = 11;               // pin 10 on L293D IC

void setup()  
{
  BlueTooth.begin(9600);  
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() 
{
  if (BlueTooth.available())
  {
   BT_input=BlueTooth.read();
    if (BT_input=='s')
    {
      digitalWrite(motorPin1, LOW);   
      digitalWrite(motorPin2, LOW);   
      digitalWrite(motorPin3, LOW);   
      digitalWrite(motorPin4, LOW);   
      Serial.println("Motors are Off");
    }
    else if (BT_input=='l')
    {
      digitalWrite(motorPin1, LOW);   
      digitalWrite(motorPin2, HIGH);  
      digitalWrite(motorPin3, LOW);   
      digitalWrite(motorPin4, HIGH);  
      Serial.println("Motors are rotating right");
    }
    else if (BT_input=='r')
    {
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      digitalWrite(motorPin3, HIGH); 
      digitalWrite(motorPin4, LOW); 
      Serial.println("Motors are rotating left");
    }
   else if (BT_input=='u')
    {
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      digitalWrite(motorPin3, LOW); 
      digitalWrite(motorPin4, HIGH); 
      Serial.println("Backward");
    }
    else if (BT_input=='d')
    {
      digitalWrite(motorPin1, LOW); 
      digitalWrite(motorPin2, HIGH); 
      digitalWrite(motorPin3, HIGH); 
      digitalWrite(motorPin4, LOW); 
      Serial.println("Forward");
    }
  }
 
}
  
  
  

