#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ArduinoHttpClient.h>

namespace HTTPSERVER
{
    //curl -u admin:admin -F "image=@firmware.bin" esp8266-webupdate.local/firmware
    // nome do host para acesso e atualizacao via OTA. http://<HOST>.local/update_path
    const char *host = "pth9";
    const char *update_path = "/up";
    // const char* update_username = "admin";
    // const char* update_password = "espthg";

    // objetos para pagina de acesso OTA
    ESP8266WebServer httpServer(80);
    ESP8266HTTPUpdateServer httpUpdater;

    void configurarHttpServer()
    {
        MDNS.begin(host);
        httpUpdater.setup(&httpServer, update_path);
        //httpUpdater.setup(&httpServer, update_path, update_username, update_password);
        httpServer.begin();
        MDNS.addService("http", "tcp", 80);
        // Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
        // Serial.printf("HTTPUpdateServer ready! Open http://%s.local%s in your browser and login with username '%s' and password '%s'\n", host, update_path, update_username, update_password);
    }

    void checarHttpServer()
    {
        httpServer.handleClient();
        MDNS.update();
    }
}