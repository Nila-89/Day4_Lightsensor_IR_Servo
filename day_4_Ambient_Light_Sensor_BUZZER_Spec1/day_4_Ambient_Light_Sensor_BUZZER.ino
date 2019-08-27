#define LIGHT A3
#define LED A5
#define BUZZER 6
void setup() {
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // Read ambient light sensor
  
  int value = analogRead(LIGHT);
  int data = map(value, 0,1023,0, 255);
/*
  Serial.print("LIGHT : ");
  Serial.println(data);

  analogWrite(LED,data);
  */
  if(data>100){
    tone(BUZZER,400);
    Serial.print("LIGHT : ");
    Serial.println(data);
    analogWrite(LED,data);

    delay(1000);
    Serial.println("ALARM ACTIVATED");
  }
  else{
    noTone(BUZZER);
    analogWrite(LED,data);
    Serial.println("ALARM DEACTIVATED");
    delay(1000);
  }
  
}
