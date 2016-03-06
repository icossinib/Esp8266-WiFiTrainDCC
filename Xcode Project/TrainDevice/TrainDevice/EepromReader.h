#include "Arduino.h"

class EepromReader {
    private:
        const static short BSSID_MAX_LENGTH = 64;
        const static short PASSWORD_MAX_LENGTH = 64;
        const static short IP_MAX_LENGTH = 16;
        const static short EEPROM_START = 512;
        void startEeprom(int address);
        void write(String data, const short dataMaxLength);
        String read();
    public:
        EepromReader();
        void writeData(String bssid, String password, String ip);
        String getBssid();
        String getPassword();
        String getIp();
};