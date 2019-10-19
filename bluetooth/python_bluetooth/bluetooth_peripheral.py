from bluepy.btle import Peripheral, UUID, BTLEDisconnectError, DefaultDelegate

class NotificationDelegate(DefaultDelegate):
    def __init__(self):
        DefaultDelegate.__init__(self)

    def handleNotification(self, cHandle, data):
        xyz = data.decode().split('|')
        print(f"X = {xyz[0]}, Y = {xyz[1]}, Z = {xyz[2]}")

try:
    arduino = Peripheral(deviceAddr="e9:be:2d:f0:66:70")
    arduino.setDelegate(NotificationDelegate())
except BTLEDisconnectError as error:
    print(error)
    print("Peripheral not found. Is it ON?")
else:
    #services = arduino.getServices()
    characteristics = arduino.getCharacteristics()
    for characteristic in characteristics:
        try:
            print(f"Value: {characteristic.read().decode()}, UUID: {characteristic.uuid}, Handle: {characteristic.handle}, ValueHandle: {characteristic.valHandle}")
        except:
            pass
    #start_notification_data = b"\x01\x00"
    arduino.writeCharacteristic(13, bytes([1])) # arduino.writeCharacteristic(13, start_notification_data) will also work, 13 comes from "characteristic handle + 1"

    while True:
        try:
            if arduino.waitForNotifications(0.1):
                # handleNotification() gets called
                continue
            print("Waiting...")
        except KeyboardInterrupt:
            break

    arduino.disconnect()