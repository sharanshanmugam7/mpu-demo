#include<Arduino.h>
#include<Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
Adafruit_MPU6050 mpu;
float ax,ay,az,gx,gy,gz,t;
void setup()
{
  Serial.begin(115200);
  Serial.println(mpu.begin(0x69));
  Serial.println("MPU initialised !");
}
void loop()
{
  Serial.println(mpu.begin(0x69));
  sensors_event_t a,g,tm;
  mpu.getEvent(&a,&g,&tm);
  ax=a.acceleration.x;
  ay=a.acceleration.y;
  az=a.acceleration.z;
  gx=g.gyro.x;
  gy=g.gyro.y;
  gz=g.gyro.z;
  t=tm.temperature;
  Serial.print("Acceleration :- ");
  Serial.print(ax);Serial.print(" ");
  Serial.print(ay);Serial.print(" ");
  Serial.println(az);Serial.print(" ");
  Serial.print("Gyro :- ");
  Serial.print(gx);Serial.print(" ");
  Serial.print(gy);Serial.print(" ");
  Serial.println(gz);Serial.print(" ");
  Serial.println("Temperature :- ");
  Serial.println(t);
  delay(2500);
}