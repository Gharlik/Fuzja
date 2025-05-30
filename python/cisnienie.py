from __future__ import print_function
import threading
from gpiozero import Button, LED
import time
import sys
sys.path.append("../..")
from DFRobot_INA219 import INA219
import os
import smbus

ina219_reading_mA = 1000
ext_meter_reading_mA = 1000

cis = INA219(1, INA219.INA219_I2C_ADDRESS3)
def cisnienie():
    volty = cis.get_bus_voltage_V()
    zCisnienie = 3.16 * (10 ** -4) * (10 ** (0.99999 * volty))
    return {zCisnienie}
while True:
    print(cisnienie())
    time.sleep(1)