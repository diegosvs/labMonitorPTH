#include <ESP8266WiFi.h>

namespace WIFICONFIG
{

        // conexao à rede wifi
#define WIFI_AP "IPT-IoT"
#define WIFI_PASSWORD "r@cion@l"

int status = WL_IDLE_STATUS;
    

     void conectarWifi()
    {
        if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("Connecting to AP ...");
        // attempt to connect to WiFi network

        WiFi.begin(WIFI_AP, WIFI_PASSWORD);
        while (WiFi.status() != WL_CONNECTED)
        {
            digitalWrite(LED_BUILTIN, 0);
            delay(100);
        }
        Serial.println("Connected to AP");
        }
         
        
    }
}