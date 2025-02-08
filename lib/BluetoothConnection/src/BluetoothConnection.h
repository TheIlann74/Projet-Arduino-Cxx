#include "Arduino.h"
#include "BluetoothSerial.h"

class BluetoothConnection
{
public:
    BluetoothConnection();
    void bluetoothSetup();
    void bluetoothGetCommand();
    void bluetoothReceiveInformation(uint16_t pm25Value, uint16_t pmIn01Value, uint16_t totalParticulesValue);

private:
    BluetoothSerial SerialBT;
    String message;
};
    