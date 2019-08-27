#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

#define sensor A0
#define touch 1

#define deviceID "Nila12D1566942380022"
#define authnRqtNo "46lsezzin"
#define extrSysID "OPEN_TCP_001PTL001_1000007619"

#define WIFI_SSID "koreatech505 2.4G" // SSID
#define WIFI_PASS "koreatech505" //psswd
#define TAG_ID "Piezo"

IoTMakers g_im;

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
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  init_iotmakers();
}

void loop() {
  // put your main code here, to run repeatedly:
  int digitaltouch;
  int analogtouch;

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }
  
  analogtouch = analogRead(sensor);
  
  //Serial.println("Ready");
  if (analogtouch>0)
  {
    Serial.println("TOUCH");
    Serial.print("Analog Measured : ");
    Serial.println(analogtouch);
    g_im.send_numdata(TAG_ID, (int)analogtouch);
  }
  else
  {
    Serial.println("NOT TOUCH");
  }
  delay(1000);
  g_im.loop(); 
}
