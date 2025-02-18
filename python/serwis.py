from __future__ import print_function
import threading
from gpiozero import Button, LED
import time
import sys
sys.path.append("../..")
from DFRobot_INA219 import INA219
import os



ina219_reading_mA = 1000
ext_meter_reading_mA = 1000

ina = INA219(1, INA219.INA219_I2C_ADDRESS3) 

CzujnikPMin= Button(8) #czujnik paliwa min
CzujnikPMax = Button(7) #czyjnik paliwa max
Pompa = LED(11) #pompa
Pompa.on()
GeneratorP = LED(20) #generator paliwa
GeneratorP.on()
ZaworAP = LED(19) #zawor awaryjny powietrze
ZaworAP.on()
ZaworPa = LED(26) #Zawor paliwa
ZaworPa.on()
ZaworPo = LED(6) #Zawor pompy
ZaworPo.on()
GZasilanie = LED(5) #230
GZasilanie.on()
PompaTM = LED(21) #Pompa turbomolekularna
PompaTM.on()
fuzja=False
def cisnienie():
    volty = ina.get_bus_voltage_V()
    zCisnienie = 3.16 * (10 ** -4) * (10 ** (0.99999 * volty))
    return {zCisnienie}

def wylacz():
    Pompa.on()
    GeneratorP.on()
    ZaworAP.on()
    ZaworPa.on()
    ZaworPo.on()
    GZasilanie.on()
    PompaTM.on()
def zmiana_stanu(urzadzenie):
    global fuzja
    if urzadzenie == 0:
        if GZasilanie.is_lit:
            GZasilanie.off()
            time.sleep(0.5)
        else:
            GZasilanie.on()
            time.sleep(0.5)

    elif urzadzenie == 1:
        if Pompa.is_lit:
            Pompa.off()
            time.sleep(0.5)
        else:
            Pompa.on()
            time.sleep(0.5)
    elif urzadzenie == 2:
        if PompaTM.is_lit:
            PompaTM.off()
            time.sleep(0.5)
        else:
            PompaTM.on()
            time.sleep(0.5)
    elif urzadzenie == 3:
        if fuzja==True:

            fuzja=False
            time.sleep(0.5)
        else:

            fuzja=True
            time.sleep(0.5)
    elif urzadzenie == 4:
        if GeneratorP.is_lit:
            GeneratorP.off()
            time.sleep(0.5)
        else:
            GeneratorP.on()
            time.sleep(0.5)
    elif urzadzenie == 5:
        if ZaworPo.is_lit:
            ZaworPo.off()
            time.sleep(0.5)
        else:
            ZaworPo.on()
            time.sleep(0.5)
    elif urzadzenie == 6:
        if ZaworPa.is_lit:
            ZaworPa.off()
            time.sleep(0.5)
        else:
            ZaworPa.on()
            time.sleep(0.5)
    elif urzadzenie == 7:
        if ZaworAP.is_lit:
            ZaworAP.off()
            time.sleep(0.5)
        else:
            ZaworAP.on()
            time.sleep(0.5)

