#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <Servo.h>

#define deviceID "Nila12D1566942380022"
#define authnRqtNo "46lsezzin"
#define extrSysID "OPEN_TCP_001PTL001_1000007619"

#define WIFI_SSID "koreatech505 2.4G" // SSID
#define WIFI_PASS "koreatech505" //psswd
#define TAG_ID "Position"

IoTMakers g_im;
Servo myServo;
int angle = 0;
static unsigned long tick = 0;
static unsigned long tick1 = 0;

void init_iotmakers()
{
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);
  
    Serial.print(F("Connect to platform..."));
    while(g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));
  
    Serial.print(F("Auth..."));
    if(g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}



void setup() {
  Serial.begin(9600);
  init_iotmakers();
  myServo.attach(3);
  myServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }
  
  tick1 = millis();
  
  
  for (angle = 0;angle < 180; angle++)
  {
    myServo.write(angle);
    delay(20);
    tick = millis() - tick1;
    if (tick>=500)
    {
      Serial.println(tick);
      Serial.println(myServo.read());
      g_im.send_numdata(TAG_ID, (int)myServo.read());
      tick1 = millis();
    }
  }
  
  for (angle = 180;angle > 0; angle--)
  {
    myServo.write(angle);
    delay(20);
    tick = millis() - tick1;
    if (tick>=500)
    {
      Serial.println(tick);
      tick1 = millis();
      g_im.send_numdata(TAG_ID, (int)myServo.read());
    }
  }
  g_im.loop(); 
  
}
