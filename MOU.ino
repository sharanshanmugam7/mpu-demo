#include<Wire.h>
int16_t ax,ay,az,t,gx,gy,gz;
void setup() {
  Serial.begin(115200);
  Wire.begin(21,22,100000);
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.println("Setup Complete");
}

void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(true);
  Wire.beginTransmission(0x68);
  ax=Wire.read();
  ay=Wire.read();
  az=Wire.read();
  t=Wire.read();
  gx=Wire.read();
  gy=Wire.read();
  gz=Wire.read();
  Serial.println(ax);
  Serial.println(ay);
  Serial.println(az);
  Serial.println(t);
  Serial.println(gx);
  Serial.println(gy);
  Serial.println(gz);
}
