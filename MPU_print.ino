#include<Wire.h>
#include<Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
Adafruit_MPU6050 mpu;
float ax,ay,az,gx,gy,gz,t;
float gxx,gyy,gzz;
float gyxError=0.07;
float gyyError=0.03;
float gyzError=0.01;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.begin();
  if(!mpu.begin())
  {
    Serial.println("Failed to initialise MPU");
  }
  Serial.println("Initialised MPU");
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
}

void loop() {
  Serial.println(mpu.begin());
  sensors_event_t accE,gyE,temp;
  mpu.getEvent(&accE,&gyE,&temp);
  ax=accE.acceleration.x;
  ay=accE.acceleration.y;
  az=accE.acceleration.z;
  gx=gyE.gyro.x;
  if(abs(gx)>gyxError)
  {
    gxx+=gx/50.00;
  }
  gy=gyE.gyro.y;
  if(abs(gy)>gyyError)
  {
    gyy+=gy/70.00;
  }
  gz=gyE.gyro.z;
  if(abs(gz)>gyzError)
  {
    gzz+=gz/90.00;
  }
  t=temp.temperature;
  Serial.print("Acceleration X :- ");
  Serial.println(ax);
  Serial.print("Acceleration Y :- ");
  Serial.println(ay);
  Serial.print("Acceleration Z :- ");
  Serial.println(az);
  Serial.print("Rotation X :- ");
  Serial.println(gx);
  Serial.print("Rotation Y :- ");
  Serial.println(gy);
  Serial.print("Rotation Z :- ");
  Serial.println(gz);
  Serial.print("Temperatre :- ");
  Serial.println(t);
  delay(3000);
}
