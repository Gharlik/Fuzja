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
nap = INA219(1, INA219.INA219_I2C_ADDRESS4)
nat = INA219(1, INA219.INA219_I2C_ADDRESS2)

bus1 = smbus.SMBus(1)                                       #trzeba potpiąć odpowiedni pin w bus

config1 = [0x00, 0x00]
bus1.write_i2c_block_data(0x18, 0x01, config1)

bus1.write_byte_data(0x18, 0x08, 0x03)
time.sleep(0.5)

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
Fuzja = LED(27) #Pompa turbomolekularna
Fuzja.off()

def temperatura():
    data = bus1.read_i2c_block_data(0x18, 0x05, 2)
    ctemp = ((data[0] & 0x1F) * 256) + data[1]
    if ctemp > 4095:
        ctemp -= 8192
    ctemp = ctemp * 0.0625
    zTemperatura = round(ctemp,1)
    return {zTemperatura}

def cisnienie():
    volty = cis.get_bus_voltage_V()
    zCisnienie = round(0.1 * (10 ** (volty-2.5)),2)
    return {zCisnienie}
def napiecie():
    volty = nap.get_bus_voltage_V()
    zNapiecie = round(volty*9.6,1)
    return {zNapiecie}
def natezenie():
    volty = nat.get_bus_voltage_V()
    zNatezenie = round(volty*10.6,1)
    return {zNatezenie}

def wylacz():
    Pompa.on()
    GeneratorP.on()
    ZaworAP.on()
    ZaworPa.on()
    ZaworPo.on()
    GZasilanie.on()
    PompaTM.on()
    Fuzja.off()
def zmiana_stanu(urzadzenie):
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
        if Fuzja.is_lit:
            Fuzja.off()
            time.sleep(0.5)
        else:
            Fuzja.on()
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

