/*

MAIN AIRBAG SYSTEM
ARDUINO MEGA

INCLUDES CODE FOR:
> DC PIEZO BUZZER
> MPU 6050 (ACCELEROMETER & GYROSCOPE)
> GPS (TO BE ADDED)
> GSM (TO BE ADDED)
> AIRBAG TRIGGER (TO BE ADDED)

*/

/*
PREPROCESSORS
*/
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

// ================================ //

/*
VARIABLES
*/

// var for sos()
const int sos_seq[] = {70, 200, 70};
const int sos_c = 3;

// var for fallDetect()
struct MPUData {
  float accelX;
  float accelY;
  float accelZ;

  float gyroX;
  float gyroY;
  float gyroZ;
};

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

// ================================ //

/*
PROTOTYPES
*/
void sos(int pin, unsigned int freq);
MPUData fallDetect();

// ================================ //

/*
MAIN CODE
*/

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  pinMode(buzPin, OUTPUT);
}

void loop()
{
  MPUData data = fallDetect();
  bool accelTrig = data.accelX > 2 || data.accelY > 2 || data.accelZ > 2;
  bool gyroTrig = data.gyroX < 45 || data.gyroY < 45 || data.gyroZ < 45;
  if (accelTrig & gyroTrig)
  {
    sos(13, 1000);
  }
}

// ================================ //

/*
FUNCTIONS
*/

// plays repeating SOS sound on the buzzer
void sos(int pin, unsigned int freq)
{
  for (int i = 0; i < sos_c; i++)
  {
    for (int j = 0; j < sos_c; j++)
    {
      tone(pin, freq);
      delay(sos_seq[i]);
      noTone(pin);
      delay(sos_seq[i]);
    }
    delay(200);
  }
}

// detects a certain angle with MPU 6050
MPUData fallDetect()
{
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  MPUData data;

  // Convert accelerometer data to m/s² (±2g range, 1g = 16384 LSB)
  data.accelX = (ax / 16384.0) * 9.81;
  data.accelY = (ay / 16384.0) * 9.81;
  data.accelZ = (az / 16384.0) * 9.81;

  // Convert gyroscope data to degrees per second (±250°/s, 1°/s = 131 LSB)
  data.gyroX = gx / 131.0;
  data.gyroY = gy / 131.0;
  data.gyroZ = gz / 131.0;

  // Optional: Print input
  // Input must be logged on a CSV file in later implementations

  Serial.print("Accel X=");
  Serial.print(data.accelX);
  Serial.print("Accel Y=");
  Serial.print(data.accelY);
  Serial.print("Accel Z=");
  Serial.print(data.accelZ);

  Serial.print("Gyro X=");
  Serial.print(data.gyroX);
  Serial.print("Gyro Y=");
  Serial.print(data.gyroY);
  Serial.print("Gyro Z=");
  Serial.print(data.gyroZ);

  delay(500);
  return data;
}