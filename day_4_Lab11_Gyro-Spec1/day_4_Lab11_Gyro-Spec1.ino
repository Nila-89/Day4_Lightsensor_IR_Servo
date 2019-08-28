#include <Wire.h>
const int MPU = 0x68;
int16_t acx, acy, acz, tmp, gyx, gyy, gyz;
double tx,t,tf;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU);
  Wire.write(0x1B);
  Wire.write(0xF8);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU);
  Wire.write(0x1C);
  Wire.write(0xF8);
  Wire.endTransmission(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  acx = Wire.read() << 8 | Wire.read();
  acy = Wire.read() << 8 | Wire.read();
  acz = Wire.read() << 8 | Wire.read();   
  tmp = Wire.read() << 8 | Wire.read();
  gyx = Wire.read() << 8 | Wire.read();
  gyy = Wire.read() << 8 | Wire.read();
  gyz = Wire.read() << 8 | Wire.read();

  int xaxis = (acx - 1090);
  int yaxis = (acy - 930);
  int zaxis = (acz - 1000);

  //temperature correction
  int temp = -1600;

  //gyro correction
  int GyX = 480;
  int GyY = 170;
  int GyZ = 210;
  

  Serial.print("xaxis : ");
  Serial.print(xaxis);
  Serial.println();
  Serial.print("yaxis : ");
  Serial.print(yaxis);
  Serial.println();
  Serial.print("zaxis : ");
  Serial.print(zaxis);
  Serial.println();

//temperature calculation
tx = tmp+temp;
t=tx/340+36.53; //equation for temperature in deg
tf=(t*9/5)+32; //farenheit

  
  Serial.print("temp : ");
  Serial.print(tf);
  Serial.println();
  Serial.print("G Y axis : ");
  Serial.print(gyy+GyX);
  Serial.println();
  Serial.print("G X axis : ");
  Serial.print(gyx+GyY);
  Serial.println();
  Serial.print("G Z axis : ");
  Serial.print(gyz+GyZ);
  Serial.println();
  Serial.println();
  delay(1000);
}
