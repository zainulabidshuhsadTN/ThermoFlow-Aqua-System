# ThermoFlow Aqua System

## Overview
The ThermoFlow Aqua System is an embedded solution designed to monitor and reuse condensation water using real-time temperature and flow sensing. It helps improve water efficiency by converting waste condensation into a usable resource.

## Features
- Real-time temperature monitoring
- Flow rate measurement
- Condensation water reuse
- LCD-based live display

## Components Used
- Arduino UNO
- DS18B20 Temperature Sensor
- Water Flow Sensor
- 16x2 LCD (I2C)

## Pin Configuration
- DS18B20 Data → D2
- Flow Sensor Output → D3
- LCD SDA → A4
- LCD SCL → A5
- VCC → 5V
- GND → GND

## Working Principle
Condensed water is collected and passed through a flow sensor to measure the rate of water movement. A temperature sensor continuously monitors water temperature. The system processes this data and displays real-time values on an LCD, enabling efficient monitoring and reuse.

## Future Improvements
- Automatic valve control
- IoT dashboard integration
- Overflow detection system
