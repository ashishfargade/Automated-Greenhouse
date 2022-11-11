# Automated-Greenhouse
#### Automated Greenhouse using Arduino UNOs, used to control soil moisture, air humidity, and temperature inside, with current conditions visible on the LCD screen.

## Components Used :
###### 2 Arduino microcontrollers are fitted with the following components:
_Refer to the image files in the project too!_

## System 1 - Arduino UNO 1
1) 16*2 LCD through I2C
2) DHT11 Sensor
3) L298n Motor Driver --> _to drive BLDC fans_
4) 90mm BLDC fans (X2)
5) A warm light bulb

## System 2 - Arduino UNO 2
1) 16*2 LCD through I2C
2) DHT11 Sensor
3) 1 Mistifier --> _mistifier is dipped in water, in a small reservoir(1) inside the greenhouse_
4) DC 5V Humidifier --> _powered through a external supply, controlled through a **DC solid state relay**. You can also use a single channel 5V relay module_
5) Soil moisture sensors (X2)
6) Water pump --> _used to irrigate the soil, water pump is dipped in the reservoir(2) outside, with a pipe running inside the greenhouse_