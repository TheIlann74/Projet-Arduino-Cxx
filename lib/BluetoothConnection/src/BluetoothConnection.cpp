#include <BluetoothConnection.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothConnection::BluetoothConnection() {
    
}

void BluetoothConnection::bluetoothSetup() {
    SerialBT.begin("ESP32Fire");
    Serial.println("The device started, now you can pair it with bluetooth!");
}

void BluetoothConnection::bluetoothGetCommand() {
    if (SerialBT.available()) {
        char incomingChar = SerialBT.read();
        if (incomingChar != '\n') {
            message += String(incomingChar);
        } else {
            message = "";
        }
        Serial.write(incomingChar);
    }
    
    if (message == "SET REBOOT")
    {
        SerialBT.println("REBOOT");
        ESP.restart();
    }
    
}

void BluetoothConnection::bluetoothReceiveInformation(uint16_t pm25Value, uint16_t pmIn01Value, uint16_t totalParticulesValue) {
    SerialBT.println("PM 2.5 (ug/m3): ");
    SerialBT.println(pm25Value);
    SerialBT.println();
    SerialBT.println("1.0 um in 0.1 L air: ");
    SerialBT.println(pmIn01Value);
    SerialBT.println("2.5 um in 0.1 L air: ");
    SerialBT.println(totalParticulesValue);
    SerialBT.println("");
}