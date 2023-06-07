#include "Keyboard.h"

int Button=6, Y=5, R=2, G=3, B=4;  
    
 void setup(void)  

{  

  Serial.begin(9600);           //Turn on the Serial Port at 9600 bps  

  pinMode(Button, INPUT_PULLUP);   

  pinMode(R, INPUT_PULLUP);        

   pinMode(G, INPUT_PULLUP);        

   pinMode(B, INPUT_PULLUP);        

  pinMode(Y, INPUT_PULLUP);   //Enable the pull-up resistor on  button   

    

 }  

    

 void loop(void)  

 {  

  Serial.print("X=");   //x控制转视角

  Serial.print(analogRead(0));    //Read the position of the joysticks X axis and print it on the serial port.  

  if(analogRead(0)>700){
    //左摇
    Keyboard.write('Q'); 
  }QQEEE

  if(analogRead(0)<300){
    //右摇
    Keyboard.write('E'); 
  }

  Serial.print(",");  

  Serial.print("Y=");   

  Serial.print(analogRead(1));    //Read the position of the joysticks Y axis and print it on the serial port.  

   Serial.print(",");  

   

   Serial.print(digitalRead(Button));    

   Serial.print(digitalRead(R));
   if(digitalRead(R) == 0){
    Keyboard.write(KEY_UP_ARROW); 
   }
    
  Serial.print(digitalRead(G)); 
  if(digitalRead(G) == 0){
    Keyboard.write(KEY_LEFT_ARROW); 
   }

   Serial.print(digitalRead(B));
   if(digitalRead(B) == 0){
    Keyboard.write(KEY_DOWN_ARROW); 
   }

   Serial.println(digitalRead(Y)); 
   if(digitalRead(Y) == 0){
     Keyboard.write(KEY_RIGHT_ARROW);
   }
   //Read the value of the select button and print it on the serial port.  

    

  delay(100); //Wait for 100 ms, thffen go back to the beginning of 'loop' and repeat.  

 } 


//不能同时监视两个串口
