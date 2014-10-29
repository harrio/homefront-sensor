homefront-sensor
================

A simple Arduino environment sensors for the Homefront platform. Sends data in JSON every time a character is received through the serial connection.

## temperature

Meant for one DHT22 temperature/humidity sensors and two DS18B20 temperature sensors.

## temperature_lite 

Same functionality but without the DS18B20 sensors.

Diagram describes a full setup with Bluetooth serial connection (HC-06 breakout was used, not whatever was available in Fritzing for the diagram).

![Connections](https://raw.github.com/harrio/harrio.github.io/master/img/temperature.png)