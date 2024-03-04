
#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include <DHT11.h>


DHT11 dht11(7);

SoftwareSerial serial_connection(4,5); //tx,rx 
TinyGPSPlus gps;// GPS object to process the NMEA data
void setup()
{
    
    Serial.begin(9600);
    

    dht11.setDelay(1000);
  Serial.begin(9600);                //This opens up communications to the Serial monitor in the Arduino IDE
  serial_connection.begin(9600);     //This opens up communications to the GPS
  Serial.println("GPS Start");        //To show in the serial monitor that the sketch has started
}

void loop()
{
  while(serial_connection.available())              //While there are incoming characters  from the GPS
  {
    gps.encode(serial_connection.read());           //This feeds the serial NMEA data into the library one char at a time
  }
  if(gps.location.isUpdated())          //This will pretty much be fired all the time anyway but will at least reduce it to only after a package of NMEA data comes in
  {
    //Get the latest info from the gps object which it derived from the data sent by the GPS unit
    Serial.print("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.print("Latitude:");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude:");
    Serial.println(gps.location.lng(), 6);
    
    Serial.print("Altitude Feet:");
    Serial.println(gps.altitude.feet());
    Serial.println("");

    Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  
  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".GMT");
  }
  Serial.println("");
  delay(2000);
  }
  





void setup() {
 // Set this to the desired delay. Default is 500ms.
}

void loop() {
    int temperature = 0;
    int humidity = 0;

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht11.readTemperatureHumidity(temperature, humidity);

    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
        // Print error message based on the error code.
        Serial.println(DHT11::getErrorString(result));
    }
}