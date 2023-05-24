#include <Adafruit_MPU6050.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void)
{
    Serial.begin(115200);

    while (!Serial)
    {
        delay(10);
    }

    Serial.println("Adafruit MPU6050 test!");
    
    // Try to initialize!
    if (!mpu.begin())
    {     
        Serial.println("Failed to find MPU6050 chip");
        while (1)
        {
            delay(10);
        }
    }
    Serial.println("MPU6050 Found!");

    // Set accelerometer range (Gs)
    mpu.setAccelerometerRange(MPU6050_RANGE_4_G);

    // Set gyro range (rad/s)
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);

    // Set filter bandwith
    mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

    Serial.println("");
    delay(200);
}

void loop()
{
    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    /* Print out the values */
    Serial.print("Acceleration X: ");
    Serial.print(a.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(a.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");

    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");

    Serial.println("");
    delay(1000);
}