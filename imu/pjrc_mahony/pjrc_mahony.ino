#include <Arduino_LSM9DS1.h>
#include "MahonyAHRS.h"
Mahony filter;
unsigned long microsPerReading, microsPrevious;
float accl_scale, gyro_scale;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Serial.println("Started");
    int imu = IMU.begin();
    if (!imu) {
    Serial.println("Failed to initialize IMU!");
    while (1);
    }
    filter.begin(119);// 119 //LSM9DS1's accelerometer and gyro sample rates have been fixed at 104

    delay(10000);

    Serial.print("Accelerometer sample rate = ");
    Serial.print(IMU.accelerationSampleRate());
    Serial.println(" Hz");
    Serial.println();
    Serial.println("Acceleration in G's");
    Serial.println("X\tY\tZ");
    Serial.print("Gyroscope sample rate = ");
    Serial.print(IMU.gyroscopeSampleRate());
    Serial.println(" Hz");
    Serial.println();
    Serial.println("Gyroscope in degrees/second");
    Serial.println("X\tY\tZ");
    Serial.print("Magnetic field sample rate = ");
    Serial.print(IMU.magneticFieldSampleRate());
    Serial.println(" uT");
    Serial.println();
    Serial.println("Magnetic Field in uT");
    Serial.println("X\tY\tZ");
    microsPerReading = 1000000 / 119;
    microsPrevious = micros();
}

void loop() {
    float ax, ay, az; //acclerometer reading is already in G / sec
    float gx, gy, gz; //Gyroscope reading is already in degrees / sec
    float mx, my, mz;
    float roll, pitch, heading;
    unsigned long microsNow;
    microsNow = micros();
    if (microsNow - microsPrevious >= microsPerReading){
    //if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
        IMU.readAcceleration(ax, ay, az);
        IMU.readGyroscope(gx, gy, gz);
        IMU.readMagneticField(mx, my, mz);
        // Serial.print(ax);
        // Serial.print('\t');
        // Serial.print(ay);
        // Serial.print('\t');
        // Serial.print(az);
        // Serial.print('\t');
        // Serial.print(gx);
        // Serial.print('\t');
        // Serial.print(gy);
        // Serial.print('\t');
        // Serial.println(gz);

        filter.update(gx, gy, gz, ax, ay, az, mx, my, mz); //for all 3
        //filter.updateIMU(gx, gy, gz, ax, ay, az);//only for accl, gyro
        roll = filter.getRoll();
        pitch = filter.getPitch();
        heading = filter.getYaw();
        Serial.print("Orientation: ");
        Serial.print(heading);
        Serial.print(" ");
        Serial.print(pitch);
        Serial.print(" ");
        Serial.println(roll);
        microsPrevious = microsPrevious + microsPerReading;
    }
}
