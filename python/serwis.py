import time
import threading
from gpiozero import Button, LED

CzujnikC = Button(1) #czujnik cisnienia
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
Fuzja = LED(2) #Fuzja
GZasilanie = LED(5) #230
GZasilanie.on()
PompaTM = LED(21) #Pompa turbomolekularna
PompaTM.on()
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

