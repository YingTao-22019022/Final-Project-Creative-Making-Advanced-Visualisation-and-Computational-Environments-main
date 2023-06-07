#include <NewPing.h>
#include <Keyboard.h>
#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7
#define trigPin4 8
#define echoPin4 9
#define maxDistance 400
#define sensorPin A0

NewPing sonar1( trigPin1, echoPin1, maxDistance);
NewPing sonar2( trigPin2, echoPin2, maxDistance);
NewPing sonar3( trigPin3, echoPin3, maxDistance);
NewPing sonar4( trigPin4, echoPin4, maxDistance);
void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin( 9600 );
  Keyboard.begin();
 
}

void loop() {
  int val = analogRead(sensorPin);
    Serial.print("sound");
    Serial.println(val);
  
 Serial.println( sonar1.ping_cm() );
 Serial.println( sonar2.ping_cm() );
 //delay(100);
 int a = sonar1.ping_cm();
  if (a <= 20 && a != 0) {
    Keyboard.press('z');
    Keyboard.releaseAll();
     }
 int b = sonar2.ping_cm();
   if (b <= 20 && b != 0) {
    Keyboard.press('x');
    Keyboard.releaseAll();
     }
 int c = sonar3.ping_cm();
   if (c <= 20 && c != 0) {
    Keyboard.press('c');
    Keyboard.releaseAll();
     }
  int d = sonar4.ping_cm();
   if (d <= 20 && d != 0) {
    Keyboard.press('v');
    Keyboard.releaseAll();
     }
 if(val>50&&val<200){
   Keyboard.write('f');
  }
  }
