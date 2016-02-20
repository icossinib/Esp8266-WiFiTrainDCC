class EepromManager {
  private:
    static byte BSSID_MAX_LENGTH;
    static byte PASSWORD_MAX_LENGTH;
    static byte IP_MAX_LENGTH;
  public:
    EepromManager();
    void writeData(String bssid, String password, String ip);
    String getBssid();
    String getPassword();
    String getIp();
};

