#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <ArduinoJson.h>

namespace PTH
{
    // pinos e modelo DHT
#define DHTPIN 0 // PIN0 - D3
#define DHTTYPE DHT22

    String aquisitarUmidade();
    String aquisitarTemperatura();
    String aquisitarPressao();

    // objeto para iniciar DHT sensor.
    DHT dht(DHTPIN, DHTTYPE);

    //    objeto para iniciar BMP280 ---> I2C PIN 5 D1 - SCL / PIN4 D2 - SDA
    Adafruit_BMP280 bmp; // sensor bmp conecta pela i2c

    String formatarPayloadTemperaturaUmidade()
    {
        String payload = "{";
        payload += "\"temperatura\":";
        payload += aquisitarTemperatura();
        payload += ",";
        payload += "\"umidade\":";
        payload += aquisitarUmidade();
        payload += "}";

        // String payload = "{";
        // payload += "\"temperatura\":";
        // payload += temperature;
        // payload += ",";
        // payload += "\"umidade\":";
        // payload += humidity;
        // payload += ",";
        // payload += "\"pressão\":";
        // payload += pressure;
        // payload += "}";

        return payload;
    }

    String formatarPayloadTemperaturaUmidadePressao()
    {
        // String payload = "{";
        // payload += "\"temperatura\":";
        // payload += aquisitarTemperatura();
        // payload += ",";
        // payload += "\"umidade\":";
        // payload += aquisitarUmidade();
        // payload += "}";

        String payload = "{";
        payload += "\"temperatura\":";
        payload += aquisitarTemperatura();
        payload += ",";
        payload += "\"umidade\":";
        payload += aquisitarUmidade();
        payload += ",";
        payload += "\"pressão\":";
        payload += aquisitarPressao();
        payload += "}";

        return payload;
    }

    String aquisitarTemperatura()
    {
        float t = dht.readTemperature();
        String temperature = String(t);
        return temperature;
    }

    String aquisitarUmidade()
    {
        float h = dht.readHumidity();

        String humidity = String(h);

        return humidity;
    }

    String aquisitarPressao()
    {
        float p = bmp.readPressure();

        String pressure = String(p);

        return pressure;
    }

    void iniciarSensores()
    {
        dht.begin();
        bmp.begin(0x76);
    }

}