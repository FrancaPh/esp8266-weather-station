![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
![forthebadge](https://forthebadge.com/images/badges/powered-by-black-magic.svg)
![forthebadge](https://forthebadge.com/images/badges/uh-oh-404-no-pages-or-badges.svg)

![Star Badge](https://img.shields.io/static/v1?label=%F0%9F%8C%9F&message=If%20Useful&style=style=flat&color=BC4E99)
![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)
[![View My Profile](https://img.shields.io/badge/View-My_Profile-green?logo=GitHub)](https://github.com/FrancaPh)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
# ESP8266 Weather Station & Logger

This repository contains two Arduino sketches for creating a weather station and a weather logger using ESP8266 microcontrollers. The weather station retrieves weather data from the OpenWeatherMap API and displays it on an OLED screen, while the weather logger reads temperature and humidity data from a DHT11 sensor and sends it to ThingSpeak for logging.

## Weather Station

### Overview

The weather station Arduino sketch is designed for an ESP8266 NodeMCU v3 microcontroller, utilizing an SH1106 OLED display for visualizing weather data. It fetches weather information from the OpenWeatherMap API and displays current conditions and forecasts. Additionally, it integrates a BME280 sensor for local temperature, pressure, and humidity measurements.

### Features

- **WiFi Connectivity:** Connects to a specified WiFi network to access the internet for weather data.
- **Real-time Clock:** Utilizes the ESP8266's capabilities to maintain accurate time.
- **OpenWeatherMap Integration:** Retrieves current weather information and forecasts from the OpenWeatherMap API.
- **OLED Display:** Utilizes the SH1106 OLED display to present weather information in a clear and organized manner.
- **Local Measurements:** Incorporates a BME280 sensor for local temperature, pressure, and humidity measurements.
- **User Interface:** Implements a basic user interface to display date, time, current weather, forecasts, and local measurements.

### Hardware Requirements

- ESP8266 NodeMCU v3 microcontroller
- SH1106 OLED display
- BME280 temperature, pressure, and humidity sensor

#### Weather Station Setup:
   ![Weather Station Setup](https://github.com/FrancaPh/esp8266-weather-station/blob/main/Schematics/WeatherStation.svg)

### Libraries

The following libraries are used in this project. Make sure to install them in your Arduino IDE before uploading the sketch:

- [ESP8266WiFi](https://github.com/esp8266/Arduino)
- [ESPHTTPClient](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient)
- [JsonListener](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266JSON)
- [SH1106Wire](https://github.com/ThingPulse/esp8266-oled-ssd1306)
- [OLEDDisplayUi](https://github.com/ThingPulse/esp8266-oled-ssd1306)
- [OpenWeatherMapCurrent](https://github.com/ThingPulse/esp8266-weather-station/tree/master)
- [OpenWeatherMapForecast](https://github.com/ThingPulse/esp8266-weather-station/tree/master)
- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)
- [Adafruit_BME280](https://github.com/adafruit/Adafruit_BME280)
- [ThingspeakClient](https://github.com/mathworks/thingspeak-arduino)

## Weather Logger

### Overview

The weather logger Arduino sketch is designed for an ESP8266 ESP01 module and a DHT11 sensor. It logs temperature and humidity data to ThingSpeak for further analysis. This sketch is ideal for creating a simple weather logging system.

### Features

- **WiFi Connectivity:** Connects to a specified WiFi network to send data to ThingSpeak.
- **DHT11 Sensor Integration:** Reads temperature and humidity data from the DHT11 sensor.
- **Data Logging:** Sends sensor data to ThingSpeak for logging and analysis.

### Hardware Requirements

- ESP8266 ESP01 module
- DHT11 temperature and humidity sensor

#### Weather Logger Setup:
   ![Weather Logger Setup](https://github.com/FrancaPh/esp8266-weather-station/blob/main/Schematics/WeatherLogger.svg)

### Libraries

The following library is used in this project:

- [ESP8266WiFi](https://github.com/esp8266/Arduino)
- [DHT](https://github.com/adafruit/DHT-sensor-library)

## Version History

### WeatherStation

- **v1.0:** Setting up the ESP8266 for WiFi connection.
- **v1.1:** Structuring the time system.
- **v1.2:** Connecting to the OpenWeatherMap API and decoding the JSON file.
- **v1.3:** Configuring the OLED SH1106 display using the SH1106Wire library.
- **v1.4:** Adding a BME280 sensor for local temperature, pressure, and humidity measurements.

### WeatherLogger

- **v1.0:** Setting up the ESP01 for WiFi connection and the ThingSpeak Client.
- **v1.1:** Add the DHT11 sensor and send the data through HTTP requests.


## Installation and Usage

1. Clone or download the repository.

2. Open each Arduino sketch in your Arduino IDE.

3. Install the required libraries for each sketch.

4. Configure the WiFi credentials and API keys in the sketches.

5. Upload each sketch to its respective ESP8266 board.

6. Connect the necessary hardware components according to the provided instructions.

7. Power on the devices and connect them to the specified WiFi network.

8. The weather station will display weather information on the OLED screen, while the weather logger will start sending data to ThingSpeak.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
