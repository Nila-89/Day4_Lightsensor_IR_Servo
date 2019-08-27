#define trigpin 13                 
#define echopin 12                
//#define BUZZER 6
#define R 3
#define G 9
#define B 10


void setup()
{
  Serial.begin (9600);       
  pinMode(trigpin, OUTPUT);   
  pinMode(echopin, INPUT);   
  //pinMode(BUZZER, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop()
{ 
  long duration, distance;
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*17/1000;

  set_color(distance,255,255);
  Serial.println(distance);

  delay(1000);
}

void set_color(int red, int green, int blue)
{
  analogWrite(R,red*10);
  analogWrite(G,255);
  analogWrite(B,255);
}

  
  
  
