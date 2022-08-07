#include <ESP8266WiFi.h>
#include<DHT.h>

DHT dht(D1,DHT11);

WiFiClient client;
WiFiServer server(80);

void setup()
  {Serial.begin(9600);
      Serial.print("Connecting to IN1B");
      WiFi.begin("IN1B","Engineer@3344");
      while (WiFi.status() != WL_CONNECTED)
        {delay(1000);
        Serial.print(".");}
      Serial.println("");
      Serial.println("WiFi Connected");
      Serial.println("");
      server.begin();
      Serial.println("Server started");
      Serial.print(WiFi.localIP());
      Serial.println("/");
      dht.begin();
  }
  
String APIKey="HQOF9PT0DL53FX22";

void loop()
    { float h = dht.readHumidity();
      float t = dht.readTemperature();
      Serial.println("Temperature: " + (String) t);
      Serial.println("Humidity: " + (String) h);
      
      if (client.connect("api.thingspeak.com", 80))
        { String postStr = APIKey + "&field1=" + String(t) + "&field2=" + String(h) + "\r\n\r\n" + "\r\n\r\n";
          client.print("POST /update HTTP/1.1\n");
          client.print("Host: api.thingspeak.com\n");
          client.print("Connection: close\n");
          client.print("X-THINGSPEAKAPIKEY: " + APIKey + "\n");
          client.print("Content-Type: application/x-www-form-urlencoded\n");
          client.print("Content-Length: ");
          client.print(postStr.length());
          client.print("\n\n");
          client.print(postStr);
          delay(100);}
      else 
        { client.stop();}
        
      delay(1000);
   }
