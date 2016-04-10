class Status {
private:
    static const int STATUS_LED = 2;
    int currentStatus;
    int ledStatus;
    int ledPeriod;
public:
    
    static const int WIFI_WAITING = 0;
    static const int WIFI_CONNECTED = 1;
    static const int WIFI_CONNECTING = 2;
    static const int WIFI_ERROR = 3;
    
    Status(const int statusValue);
    Status(const int statusValue, const int statusLed);
    void setStatus(int newStatus);
    int getStatus();
    void showStatus();
    void blinkLed();
};