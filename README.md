![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
![forthebadge](https://forthebadge.com/images/badges/powered-by-black-magic.svg)
![forthebadge](https://forthebadge.com/images/badges/uh-oh-404-no-pages-or-badges.svg)

![Star Badge](https://img.shields.io/static/v1?label=%F0%9F%8C%9F&message=If%20Useful&style=style=flat&color=BC4E99)
![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)
[![View My Profile](https://img.shields.io/badge/View-My_Profile-green?logo=GitHub)](https://github.com/FrancaPh)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/FrancaPh/esp8266-weather-station/blob/main/LICENSE)

# ESP8266 Weather Station

## Overview

This Arduino sketch is designed for a weather station using an ESP8266 microcontroller, an OLED display (SH1106), and the OpenWeatherMap API to fetch weather data. The project aims to provide a compact and informative display of current weather conditions and forecasts, now also including local temperature and humidity measurements using a DHT11 sensor.

## Features

- **WiFi Connectivity:** Connects to a specified WiFi network to access the internet for weather data.
- **Real-time Clock:** Utilizes the ESP8266's capabilities to maintain accurate time.
- **OpenWeatherMap Integration:** Retrieves current weather information and forecasts from the OpenWeatherMap API.
- **OLED Display:** Utilizes the SH1106 OLED display to present weather information in a clear and organized manner.
- **User Interface:** Implements a basic user interface to display date, time, current weather, forecasts, local temperature, and humidity.

## Hardware Requirements

- ESP8266 microcontroller
- SH1106 OLED display
- DHT11 temperature and humidity sensor (new addition)

## Libraries

The following libraries are used in this project. Make sure to install them in your Arduino IDE before uploading the sketch:

- **[ESP8266WiFi](https://github.com/esp8266/Arduino):** For ESP8266 WiFi connectivity.
- **[ESPHTTPClient](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient):** Allows the ESP8266 to make HTTP requests.
- **[JsonListener](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266JSON):** A library for parsing JSON data.
- **[SH1106Wire](https://github.com/ThingPulse/esp8266-oled-ssd1306):** Library for controlling SH1106-based OLED displays.
- **[OLEDDisplayUi](https://github.com/ThingPulse/esp8266-oled-ssd1306):** A library for creating user interfaces on OLED displays.
- **[Wire](https://www.arduino.cc/en/reference/wire):** I2C communication library.
- **[OpenWeatherMapCurrent](https://github.com/ThingPulse/esp8266-weather-station/tree/master):** Library for interfacing with the OpenWeatherMap Current Weather API.
- **[OpenWeatherMapForecast](https://github.com/ThingPulse/esp8266-weather-station/tree/master):** Library for interfacing with the OpenWeatherMap Forecast API.
- **[DHT](https://github.com/adafruit/DHT-sensor-library):** Library for DHT11 sensor.
- **[ThingspeakClient](https://github.com/mathworks/thingspeak-arduino):** Library for interfacing with ThingSpeak API.

## Setup

1. Clone or download the project from the [GitHub repository](https://github.com/FrancaPh/esp8266-weather-station).

2. Open the Arduino IDE, install the necessary libraries mentioned in the code, and upload the sketch to your ESP8266 board.

3. Connect the ESP8266 to the OLED display and DHT11 sensor, ensuring the proper wiring as specified in the code.

4. Power on the device and connect it to the specified WiFi network.

5. The weather station will start displaying current weather information, forecasts, local temperature, and humidity.

## Configuration

- Adjust WiFi credentials (`WIFI_SSID` and `WIFI_PWD`) to match your network.
- Customize OpenWeatherMap API settings (`OPEN_WEATHER_MAP_APP_ID` and `OPEN_WEATHER_MAP_LOCATION_ID`).
- Modify display settings, such as I2C address and pins, to match your hardware.

## Version History

- **v1.0:** Setting up the ESP8266 for WiFi connection.
- **v1.1:** Structuring the time system.
- **v1.2:** Connecting to the OpenWeatherMap API and decoding the JSON file.
- **v1.3:** Configuring the OLED SH1106 display using the SH1106Wire library.
- **v1.4:** Adding a DHT11 sensor for local temperature and humidity measurements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

