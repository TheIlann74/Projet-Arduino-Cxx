class WifiConnection
{
public:
    WifiConnection(String ssid, String password, String autoConnectAPPassword);
    void wifiConnect();
    void verifyWifi();

private:
    String ssid;
    String password;
    String autoConnectAPPassword;
};
//             // the content of the HTTP response follows the header: