#include <OneWire.h>
#include <DallasTemperature.h>
#include <dht.h>
 
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
#define DHT22_PIN 6

dht DHT;
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial1.begin(9600);
  Serial1.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}
 
 
void loop(void)
{
  while (!Serial1.available()) { /* Do nothing. Just wait until we have a byte */ }
  Serial1.read();
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial1.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial1.println("DONE");

  float temp1 = sensors.getTempCByIndex(0);
  float temp2 = sensors.getTempCByIndex(1);
  float temp3 = -1;
  float hum3 = -1;
  
  int st = DHT.read22(DHT22_PIN);
  switch (st)
  {
    case DHTLIB_OK:  
      temp3 = DHT.temperature;
      hum3 = DHT.humidity;
      break;
    default: 
      break;
  }

  Serial1.print("[{\"key\":");
  Serial1.print("\"1\", ");
  Serial1.print("\"temp\":");
  Serial1.print(temp1);
  Serial1.print("},"); 
  
  Serial1.print("{\"key\":");
  Serial1.print("\"2\", ");
  Serial1.print("\"temp\":");
  Serial1.print(temp2);
  Serial1.print("},"); 
  
  Serial1.print("{\"key\":");
  Serial1.print("\"3\", ");
  Serial1.print("\"temp\":");
  Serial1.print(temp3);
  Serial1.print(", \"hum\":");
  Serial1.print(hum3);  
  Serial1.print(", \"st\":");
  Serial1.print(st);  
  Serial1.println("}]"); 
  delay(5000);
}



