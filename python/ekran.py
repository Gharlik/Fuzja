import time
import tkinter as tk
import threading
from tkinter import Toplevel
import matplotlib
import matplotlib.pyplot as plt
import json
from serwis import zmiana_stanu, cisnienie, wylacz,temperatura,natezenie,napiecie  # Upewnij się, że ten moduł jest dostępny

root = None
# Flagi sterujące dla wątków
a = True  # (używana gdzie indziej, jeśli potrzeba)
b = True  # do sterowania wątkiem aktualizacji danych

def wylaczwatek():
    global b
    b = False

def serwisowy(zamknij):
    global b
    b = True

    if zamknij:
        zamknij.destroy()

    serw = tk.Tk()
    serw.title("Tryb serwisowy")
    serw.geometry("1024x600")
    serw.configure(bg="black")

    label1 = tk.Label(serw,
                      text="Tryb serwisowy",
                      bg="black",
                      fg="red",
                      font=("Helvetica", 30))
    label1.grid(row=0, column=0, columnspan=2, pady=10, padx=10)

    outd = tk.Label(serw,
                    text=f"Cisnienie: {cisnienie()}, Temperatura: {temperatura()}, Naterzenie: {natezenie()}, Napiecie: {napiecie()}",
                    bg="black",
                    fg="red",
                    font=("Helvetica", 15))
    outd.grid(row=1, column=0, columnspan=2, padx=20, pady=20)

    def odczyt():
        while b:
            time.sleep(1)
            # Aktualizacja danych z czujnika
            outd.config(text=f"Cisnienie: {cisnienie()}Pa, Temperatura: {temperatura()}°C, Naterzenie: {natezenie()}mA, Napiecie: {napiecie()}Kv")

    # Przekazujemy referencję do funkcji odczyt (bez nawiasów)
    threading.Thread(target=odczyt, daemon=True).start()

    wyjscie = tk.Button(serw,
                         text="Wyjscie",
                         bg="red",
                         fg="black",
                         width=60,
                         height=1,
                         font=("Helvetica", 20),
                         command=lambda: [wylacz(), wylaczwatek(), main(serw)])
    wyjscie.grid(row=8, column=0, columnspan=2, pady=10, padx=20)

    zal = tk.Button(serw,
                    text="Główne zasilanie",
                    bg="red",
                    fg="white",
                    width=21,
                    height=1,
                    font=("Helvetica", 15),
                    command=lambda: [zmiana_stanu(0), zmiana_koloru(zal)])
    zal.grid(row=4, column=0, pady=10, padx=10)

    pomp_rot = tk.Button(serw,
                         text="Pompa rotacyjna",
                         bg="red",
                         fg="white",
                         width=21,
                         height=1,
                         font=("Helvetica", 15),
                         command=lambda: [zmiana_stanu(1), zmiana_koloru(pomp_rot)])
    pomp_rot.grid(row=5, column=0, columnspan=1, pady=10, padx=10)

    pomp_turbo = tk.Button(serw,
                           text="Pompa turbo molekularna",
                           bg="red",
                           fg="white",
                           width=21,
                           height=1,
                           font=("Helvetica", 15),
                           command=lambda: [zmiana_stanu(2), zmiana_koloru(pomp_turbo)])
    pomp_turbo.grid(row=6, column=0, columnspan=1, pady=10, padx=10)

    fuzja = tk.Button(serw,
                      text="fuzja",
                      bg="red",
                      fg="white",
                      width=21,
                      height=1,
                      font=("Helvetica", 15),
                      command=lambda: [zmiana_stanu(3), zmiana_koloru(fuzja)])
    fuzja.grid(row=7, column=0, columnspan=1, pady=10, padx=10)

    gen_paliwa = tk.Button(serw,
                           text="Generator paliwa",
                           bg="red",
                           fg="white",
                           width=21,
                           height=1,
                           font=("Helvetica", 15),
                           command=lambda: [zmiana_stanu(4), zmiana_koloru(gen_paliwa)])
    gen_paliwa.grid(row=4, column=1, columnspan=1, pady=10, padx=10)

    zaw_pompy = tk.Button(serw,
                          text="Zawor pompy",
                          bg="red",
                          fg="white",
                          width=21,
                          height=1,
                          font=("Helvetica", 15),
                          command=lambda: [zmiana_stanu(5), zmiana_koloru(zaw_pompy)])
    zaw_pompy.grid(row=5, column=1, columnspan=1, pady=10, padx=10)

    zaw_paliwa = tk.Button(serw,
                          text="Zawor paliwa",
                          bg="red",
                          fg="white",
                          width=21,
                          height=1,
                          font=("Helvetica", 15),
                          command=lambda: [zmiana_stanu(6), zmiana_koloru(zaw_paliwa)])
    zaw_paliwa.grid(row=6, column=1, columnspan=1, pady=10, padx=1)

    zaw_powietrza = tk.Button(serw,
                              text="Zawor powietrza",
                              bg="red",
                              fg="white",
                              width=21,
                              height=1,
                              font=("Helvetica", 15),
                              command=lambda: [zmiana_stanu(7), zmiana_koloru(zaw_powietrza)])
    zaw_powietrza.grid(row=7, column=1, columnspan=1, pady=10, padx=10)

    serw.mainloop()

def zmiana_koloru(x):
    zmiana = x.cget("bg")
    nowy_kolor = "green" if zmiana == "red" else "red"
    x.config(bg=nowy_kolor)

def auto(zmiana):
    if zmiana:
        zmiana.destroy()

    aut = tk.Tk()
    aut.title("Tryb automatyczny")
    aut.geometry("1024x600")
    aut.configure(bg="black")

    napis = tk.Label(aut,
                     text="Tryb automatyczny",
                     bg="black",
                     fg="red",
                     font=("Helvetica", 15))
    zalacz_auto = tk.Button(aut,
                            text="Zalacz tryb automatyczny",
                            bg="green",
                            fg="white",
                            font=("Helvetica", 15)
                            # tutaj należy dodać odwołanie do funkcji uruchamiającej tryb automatyczny
                            )
    wyjsce = tk.Button(aut,
                       text="Wyjscie",
                       bg="black",
                       fg="red",
                       font=("Helvetica", 20),
                       command=lambda: [main(aut)])
    napis.pack(pady=10)
    zalacz_auto.pack(pady=10)
    wyjsce.pack(pady=20)

def main(zamknij=None):
    if zamknij:
        zamknij.destroy()
    global root
    root = tk.Tk()
    root.geometry("1024x600")
    root.title("Reaktor fuzyjny v3")
    root.configure(bg="black")

    napis1 = tk.Label(root,
                      text="Witam",
                      font=("Helvetica", 20),
                      background="black",
                      fg="red")
    napis1.pack(pady=20)

    button1 = tk.Button(root,
                        text="Tryb serwisowy",
                        command=lambda: serwisowy(root),
                        bg="gray",
                        fg="white")
    button1.pack(pady=10)

    button2 = tk.Button(root,
                        text="Tryb automatyczny",
                        command=lambda: auto(root),
                        bg="gray",
                        fg="white")
    button2.pack(ipadx=10, ipady=10)

    root.mainloop()

try:
    main()
finally:
    a = False
    wylacz()
