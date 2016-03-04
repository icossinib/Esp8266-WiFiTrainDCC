#include <string>

class EepromReader {
    private:
        const static short BSSID_MAX_LENGTH = 64;
        const static short PASSWORD_MAX_LENGTH = 64;
        const static short IP_MAX_LENGTH = 16;
        const static int EEPROM_START = 512;
        void startEeprom(int address);
        void write(const char data[], const short dataMaxLength);
        const char *read();
    public:
        EepromReader();
        void writeData(const char bssid[], const char password[], const char ip[]);
        const char *getBssid();
        const char *getPassword();
        const char *getIp();
};

