// BMP180 reference code
// https://github.com/LowPowerLab/SFE_BMP180/blob/master/examples/SFE_BMP180_example/SFE_BMP180_example.ino

#include <SFE_BMP180.h>
#include <ESP8266WiFi.h>
 
SFE_BMP180 BMP;
char apHostName[50];
void resetHostName();

//------------------------------------------------------------------------------
 
void setup() {
  Serial.begin(9600);
  Serial.println("BOOT");
 
  // Initialize the sensor
  if (BMP.begin())
    Serial.println("BMP180 init success");
  else{
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }
 
  WiFi.mode(WIFI_AP);
}
 
//------------------------------------------------------------------------------


void loop(){
  double celsius;
 
  char status = BMP.startTemperature();
  if (status != 0){
    // Wait for the measurement to complete:
    delay(status);
 
    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Function returns 1 if successful, 0 if failure.
 
    status = BMP.getTemperature(celsius);
    if (status != 0){
      // convert Celsius to Fahrenheit
      double fahrenheit = (9.0/5.0)*celsius+32.0;
 
      // set the host name to the temperature
      sprintf(apHostName, "%.2f °C // %.2f °F", celsius, fahrenheit);
      resetHostName();
    }
  }
  delay(60000);
}

//------------------------------------------------------------------------------

void resetHostName(){
  Serial.print("Resetting host name to: ");
  Serial.println(apHostName);
  WiFi.softAPdisconnect(true);
  WiFi.softAP(apHostName);
}
