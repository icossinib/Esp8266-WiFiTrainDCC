class Status {
  private:
    static const int WIFI_CONNECTED;
    static const int WIFI_CONNECTING;
    static const int WIFI_ERROR;
    int currentStatus;
    int ledStatus;
    int ledPeriod;
  public:
    Status(int led, int status);
    void setStatus(int newStatus);
    int getStatus();
    void showStatus();
    void blinkLed();
};

