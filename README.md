# WifiTemp
A project to use an ESP8266 to broadcast the current temperature as a Wi-Fi network name

What you need for this project:
A D1 Mini - https://www.amazon.com/Makerfocus-NodeMcu-Development-ESP8266-Compatible/dp/B01N3P763C


A BMP180 sensor shield for the D1 Mini - https://www.amazon.com/ACROBOTIC-Temperature-Barometric-Raspberry-Altimeter/dp/B07G2XDS8K/

Step 1)
Solder the pins on each board

Step 2)
Connect the pins with jumper cables, giving at least 4 inches between each board to avoid heat transfer

Step 3) 
Install ESP8266 libraries in Arduino IDE, download this sketch, and flash the sketch to the D1 Mini

Step 4)
Power the D1 Mini outside, make sure the sensor is exposed to the outside and is not enclosed.

If the temperature is 5-10 degrees too high, it's probably too close to the D1 mini, or in an enclosed space that's gathering heat.

By Brandon Paiz and Kody Kinzie

![Hookup](https://i.imgur.com/JdSXPK3.jpg)

![Hookup](https://i.imgur.com/gehbDHB.jpg)
