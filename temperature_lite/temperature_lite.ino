#include <dht.h>
 
#define DHT22_PIN 6

dht DHT;
 
void setup(void)
{
  // start serial port
  Serial1.begin(9600);
}
 
 
void loop(void)
{
  while (!Serial1.available()) { /* Do nothing. Just wait until we have a byte */ }
  Serial1.read();
  
  float temp = -1;
  float hum = -1;
  
  int st = DHT.read22(DHT22_PIN);
  switch (st)
  {
    case DHTLIB_OK:  
      temp = DHT.temperature;
      hum = DHT.humidity;
      break;
    default: 
      break;
  }

  Serial1.print("[{\"key\":");
  Serial1.print("\"1\", ");
  Serial1.print("\"temp\":");
  Serial1.print(temp);
  Serial1.print(", \"hum\":");
  Serial1.print(hum);  
  Serial1.print(", \"st\":");
  Serial1.print(st);  
  Serial1.println("}]"); 
  delay(5000);
}



