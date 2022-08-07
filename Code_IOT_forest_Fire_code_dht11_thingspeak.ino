#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

DHT dht(D1, DHT11);

WiFiClient client;

void setup() 
    {Serial.begin(9600);
      WiFi.begin("IN1B", "Engineer@3344");
      while(WiFi.status() != WL_CONNECTED)
      {delay(200);
        Serial.print("..");}
      Serial.println();
      Serial.println("NodeMCU is connected!");
      Serial.println(WiFi.localIP());
      dht.begin();
      ThingSpeak.begin(client);
    }
    
long myChannelNumber = 1699122;
const char myWriteAPIKey[] = "HQOF9PT0DL53FX22";

void loop() 
    { float h = dht.readHumidity();
      float t = dht.readTemperature();
      Serial.println("Temperature: " + (String) t);
      Serial.println("Humidity: " + (String) h);
      ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
      ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
      delay(1000);
     }
