import threading
import time
a=True
def funkcja():
    while a==True:
        print("huj")
        time.sleep(1)

threading.Thread(target=funkcja).start()
print("ci")
time.sleep(2)
print("ci")
time.sleep(2)
a=False


