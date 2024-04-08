# HA_with_EspHome
My home setup with Home Assistant + Esphome, MQTT, Zigbee2Mqtt, PostgresDB

basic Home Assistent stuff + PV system with smartmeter, battery and Soyosource Inverter, which tries to reduce the house powerconsumption to 0. (zero feed/ Nulleinspeisung) :-)

"Hichi" Wifi IR reader transmits current consumption -> HomeAssistant -> ESP32 in garage -> Adjusts power demand Soyosource inverter
In Addition the ESP32 measures PV / Battery currents, temperatures, JK BMS and ensures safe operation of the Battery. Inlcuding backup operation if Wifi or HomeAssistant are not available.

Current measurements are done via two INA226 all 250ms and the Soyosource inverter is also adjusted each 250ms (which makes overshoot compensation necessary: https://github.com/syssi/esphome-soyosource-gtn-virtual-meter/pull/140)
