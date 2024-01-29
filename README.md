# ESP8266 Weather Station

## Overview

This Arduino code is designed for an ESP8266-based weather station that provides real-time weather information on an OLED display. The weather station fetches data from the OpenWeatherMap API, displays current weather conditions, forecasts, date, and time. The OLED display is configured using the SH1106Wire library, and the code includes WiFi connectivity for internet access and precise timekeeping.

## Features

- Display current weather conditions
- Display weather forecasts for the next few days
- Show date and time
- Support for both metric and imperial units
- Connects to OpenWeatherMap API for weather data
- Easily customizable settings

## Hardware Requirements

- ESP8266 board
- OLED display (SH1106)
- Internet connection

## Getting Started

1. Clone or download this repository.
2. Open the `WeatherStation.ino` file in the Arduino IDE.
3. Install the required libraries mentioned in the code.
4. Configure WiFi and OpenWeatherMap API settings in the code.
5. Upload the code to your ESP8266 board.
6. Open the Serial Monitor to view the output and debug if necessary.

## Configuration

- **WIFI_SSID:** Your WiFi network's SSID.
- **WIFI_PWD:** Your WiFi network's password.
- **UPDATE_INTERVAL_SECS:** Update interval for weather data in seconds.
- ... (Other settings)

## Library Dependencies

- [ESP8266WiFi](https://github.com/esp8266/Arduino)
- [u8g2](https://github.com/olikraus/u8g2)
- [ESPHTTPClient](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient)
- ... (Other libraries)

## Changelog

- **Version v1.0:**
  - Setting up the ESP8266 for WiFi connection

- **Version v1.1:**
  - Structuring the time system

- **Version v1.2:**
  - Connecting the OpenWeatherMap API and decoding the JSON file

- **Version v1.3:**
  - Configuring the OLED SH1106 display using SH1106Wire library

## Credits

- Original code by Pedro Franca
- u8g2 library: [https://github.com/olikraus/u8g2](https://github.com/olikraus/u8g2)
- ESP8266 Arduino Core: [https://github.com/esp8266/Arduino](https://github.com/esp8266/Arduino)
- OpenWeatherMap API: [https://openweathermap.org/api](https://openweathermap.org/api)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
