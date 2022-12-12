#include <DHT.h>
#include <Adafruit_BMP280.h>

namespace PTH
{
    // pinos e modelo DHT
#define DHTPIN 0 // PIN0 - PIN2 - PIN16
#define DHTTYPE DHT22

    // objeto para iniciar DHT sensor.
    DHT dht(DHTPIN, DHTTYPE);

    //    objeto para iniciar BMP280 ---> I2C PIN 5 - SCL / PIN4 - SDA
    Adafruit_BMP280 bmp; // sensor bmp conecta pela i2c

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