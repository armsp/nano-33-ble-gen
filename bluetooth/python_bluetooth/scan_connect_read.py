import sys
from bluepy.btle import Peripheral, Scanner, DefaultDelegate, UUID, ADDR_TYPE_PUBLIC

# class ScanDelegate(DefaultDelegate):
#     def __init__(self):
#         DefaultDelegate.__init__(self)

#     def handleDiscovery(self, dev, isNewDev, isNewData):
#         if isNewDev:
#             print ("Discovered device", dev.addr)
#         elif isNewData:
#             print ("Received new data from", dev.addr)

scanner = Scanner()#.withDelegate(ScanDelegate())
scanner.scan(10.0)
devices = scanner.getDevices()

for i, device in enumerate(devices):
    print(f"\n~~~~~~ Device {i} ~~~~~~")
    print(f"Device Address: {device.addr}, RSSI: {device.rssi}, Connectable: {device.connectable}")
    for (adtype, desc, value) in device.getScanData():
        print (f"AD Type {adtype}, Type Name: {desc}, Value: {value}")

print("\n>>>>>>>>>> Connect to Arduino Nano 33 BLE and read characteristics <<<<<<<<<<\n")

arduino = Peripheral(addrType=ADDR_TYPE_PUBLIC, iface=None)

for device in devices:
    if device.addr == "e9:be:2d:f0:66:70":
        arduino.connect(device)
        for characteristic in arduino.getCharacteristics():
            print(f"Handle: {characteristic.handle}, UUID Name: {UUID.getCommonName(characteristic.uuid)}, Value Handle: {characteristic.valHandle}, Properties: {characteristic.propertiesToString()}")
            if characteristic.supportsRead():
                print(f"{characteristic.uuid} : {characteristic.read().decode()}")
        #print(arduino.readCharacteristic(12).decode())
        #print(int.from_bytes(arduino.readCharacteristic(12), sys.byteorder)) #use this if receiving bytes
        #print(arduino.readCharacteristic(13))
        #print(arduino.readCharacteristic(22).decode('utf-8'))
