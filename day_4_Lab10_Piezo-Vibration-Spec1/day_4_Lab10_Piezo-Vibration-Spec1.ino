#define sensor A0
#define touch 1

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digitaltouch;
  int analogtouch;
  //Serial.println("Ready");
  if (analogRead(sensor)>0)
  {
    Serial.println("TOUCH");
    Serial.print("Analog Measured : ");
    Serial.println(analogRead(sensor));
  }
  else
  {
    Serial.println("NOT TOUCH");
  }
  delay(1000);
  
}
