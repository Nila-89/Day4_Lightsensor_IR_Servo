#include <Servo.h>
Servo myServo;
int angle = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(3);
}

void loop() {
  // move from 0 to 180 degrees
  static unsigned long tick = millis ();
  static unsigned long waktu=millis ();
  double x;
  

  //Serial.println(tick);
  for(int i = 0; i < 10; i++) {
    for(angle = 0; angle < 180; angle++){
    
      myServo.write(angle);
      delay(20);
   }
    
    //move in reverse direction, from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--)
    {
      myServo.write(angle);
      delay(20);
    }
    waktu=millis() - tick;
    }
    Serial.print("Time: ");
    Serial.println(waktu);

    //Calculation to find the rotation in 1 minute (rpm)
    x = ((600)/(double)waktu)*10000;
    Serial.print("Rotation in 60 sec: ");
    Serial.println(x);
    Serial.println(" ");
}

/* result 54.208 second for 10 times rotation, so the conclusion is the servo motor 
 *  has 11 Rpm, 1 rotation need 5.45 second and 60 degree need 0.9 second.
 */
