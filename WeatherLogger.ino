/* WeatherLogger.ino
written by Pedro Franca, 14.2.2024

github repository: https://github.com/FrancaPh/esp8266-weather-station

board: ESP01

changelogs: 
  version: v1.0
    notes: Setting up the ESP01 for the WiFi connection and the Thingspeak Client
  version: v1.1
    notes: Add the DHT11 sensor and send the data throw the HTTP request

license:
  MIT License

  Copyright (c) 2024 Pedro Henrique Franca

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
/*******************************
 *   Libraries instantiation   *
 *******************************/

// ESP8266 libraries
#include <ESP8266WiFi.h>

// DHT11 library
#include "DHT.h"

/**************************
 *     Begin Settings     *
 **************************/

// WIFI setup
const char* WIFI_SSID = "71C 2.4Ghz";  // Wi-Fi network SSID
const char* WIFI_PWD = "10203040";      // Wi-Fi network password

// Thingspeak settings
const char* host = "api.thingspeak.com";    // Thingspeak API host address
const char* THINGSPEAK_API_KEY = "4ZSH4A4AY2C4IK15";  // Thingspeak API key

// DHT11 settings
#define DHTPIN D4        // Pin to which the DHT11 sensor is connected
#define DHTTYPE DHT11    // Type of DHT sensor being used (DHT11 in this case)

DHT dht(DHTPIN, DHTTYPE); // DHT sensor object

// general settings
const boolean IS_METRIC = true;  // Flag indicating whether the measurements are in metric units
const int UPDATE_INTERVAL_SECONDS = 10;  // Interval between consecutive updates

/**************************
 *      End Settings      *
 **************************/

void setup() {
  Serial.begin(115200); // Initialize serial communication
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PWD);  // Connect to Wi-Fi network

  // Wait for Wi-Fi connection to be established
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  // Print local IP address
}

void loop() {
  Serial.print("connecting to ");
  Serial.println(host);

  WiFiClient client;  // Create a client object for HTTP communication
  const int httpPort = 80;  // HTTP port for communication with Thingspeak API

  // Connect to the Thingspeak server
  if (!client.connect(host, httpPort)) {
    Serial.println("connection to Thingspeak failed");
    return;
  }

  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if sensor readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Prepare URL for sending sensor data to Thingspeak
  String url = "/update?api_key=";
  url += THINGSPEAK_API_KEY;
  url += "&field1=";
  url += String(temperature);
  url += "&field2=";
  url += String(humidity);

  // Print temperature and humidity readings to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("ºC, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // Send HTTP GET request to Thingspeak
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(10);

  // Wait for response from Thingspeak server
  while (!client.available()) {
    delay(100);
    Serial.print(".");
  }

  // Read response from Thingspeak server and print it to serial monitor
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");

  client.stop();  // Close the connection to Thingspeak server

  delay(1000 * UPDATE_INTERVAL_SECONDS);  // Wait before sending next update
}
