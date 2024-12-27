import time
import threading
import gpio
from gpiozero import Button, LED

CzujnikC = Button(3) #czujnik cisnienia
CzujnikPMin= Button(5) #czujnik paliwa min
CzujnikPMax = Button(7) #czyjnik paliwa max
Pompa = LED(8) #pompa
GeneratorP = LED(10) #generator paliwa
ZaworAP = LED(11) #zawor awaryjny powietrze
ZaworPa = LED(12) #Zawor paliwa
ZaworPo = LED(13) #Zawor pompy
Fuzja = LED(15) #Fuzja
GZasilanie = LED(16) #230
PompaTM = LED(18) #Pompa turbomolekularna

def zmiana_stanu(urzadzenie):
    if urzadenie == 0:
        print("działa pierwszy")
        if GZasilanie.on():
            GZasilanie.off()
            time.sleep(0.5)
        else:
            GZasilanie.on()
            time.sleep(0.5)
    elif urzadenie == 1:
        if Pompa.on():
            Pompa.off()
            time.sleep(0.5)
        else:
            Pompa.on()
            time.sleep(0.5)
    elif urzadenie == 2:
        print("działa inne")
        if PompaTM.on():
            PompaTM.off()
            time.sleep(0.5)
        else:
            PompaTM.on()
            time.sleep(0.5)
    elif urzadenie == 3:
        if Fuzja.on():
            Fuzja.off()
            time.sleep(0.5)
        else:
            Fuzja.on()
            time.sleep(0.5)
    elif urzadenie == 4:
        if GeneratorP.on():
            GeneratorP.off()
            time.sleep(0.5)
        else:
            GeneratorP.on()
            time.sleep(0.5)
    elif urzadenie == 5:
        if ZaworPo.on():
            ZaworPo.off()
            time.sleep(0.5)
        else:
            ZaworPo.on()
            time.sleep(0.5)
    elif urzadenie == 6:
        if ZaworPa.on():
            ZaworPa.off()
            time.sleep(0.5)
        else:
            ZaworPa.on()
            time.sleep(0.5)
    elif urzadenie == 7:
        if ZaworAP.on():
            ZaworAP.off()
            time.sleep(0.5)
        else:
            ZaworAP.on()
            time.sleep(0.5)

