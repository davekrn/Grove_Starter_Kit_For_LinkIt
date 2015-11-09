#include <DHT.h>

// Example testing sketch for Temperature & Humidity Sensor Pro
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to (D2)

#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);


void setup() 
{
    Serial.begin(9600); 
    Serial.println("DHTxx test!");

    dht.begin();
}

void loop() 
{
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    
    float t = 0.0;
    float h = 0.0;
    
    if(dht.readHT(&t, &h))
    {
        Serial.println("------------------------------");
        Serial.print("temperature = ");
        Serial.println(t);
        
        Serial.print("humidity = ");
        Serial.println(h);
    }
    
    delay(2000);
}
