#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>

BLEService accelerometerService("19b10000-e8f2-537e-4f6c-d104768a1214");

BLEStringCharacteristic firstCharacteristic("19b10010-e8f2-537e-4f6c-d104768a1214",  // standard 16-bit characteristic UUID
    BLERead | BLENotify, 50); // remote clients will be able to get notifications if this characteristic changes

//String oldAcclerometerReading = "0";
//long previousMillis = 0;  // last time the battery level was checked, in ms

void setup() {
  Serial.begin(9600);    // initialize serial communication
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT); // initialize the built-in LED pin to indicate when a central is connected

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");

    while (1);
  }
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerometerSampleRate());
  Serial.println(" Hz");
  Serial.println();

  /* Set a local name for the BLE device
     This name will appear in advertising packets
     and can be used by remote devices to identify this BLE device
     The name can be changed but maybe be truncated based on space left in advertisement packet
  */
  BLE.setLocalName("Accelerometer");
  BLE.setAdvertisedService(accelerometerService); // add the service UUID
  accelerometerService.addCharacteristic(firstCharacteristic); // add the characteristic
  BLE.addService(accelerometerService); // Add the service
  firstCharacteristic.writeValue(oldAcclerometerReading); // set initial value for this characteristic

  /* Start advertising BLE.  It will start continuously transmitting BLE
     advertising packets and will be visible to remote BLE central devices
     until it receives a new connection */

  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {

  // wait for a BLE central
  BLEDevice central = BLE.central();

  // if a central is connected to the peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's BT address:
    Serial.println(central.address());
    // turn on the LED to indicate the connection:
    digitalWrite(LED_BUILTIN, HIGH);

    // while the central is connected:
    while (central.connected()) {
      //long currentMillis = millis();
      //if (currentMillis - previousMillis >= 200) {
      //  previousMillis = currentMillis;
        updateAcceleration();
      //}
    }
    // when the central disconnects, turn off the LED:
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void updateAcceleration() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    String accelerometerData = String(x)+"|"+String(y)+"|"+String(z);
    Serial.println(accelerometerData);
    firstCharacteristic.writeValue(accelerometerData);
  }
}
