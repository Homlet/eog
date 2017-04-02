import serial
import os
from time import sleep

LEFT_CMD = "osascript -e 'tell application \"System Events\" to key code 123'"
RIGHT_CMD = "osascript -e 'tell application \"System Events\" to key code 124'"

conn = serial.Serial("/dev/cu.usbmodem1411", 9600)
conn.readline()
while True:
    values = [float(x) for x in conn.readline().split(":")];
    mean = values[0]
    dev = values[1]
    if abs(dev) > 1:
        os.system(LEFT_CMD if dev > 0 else RIGHT_CMD); 
        print str(mean) + " " + str(dev)
        for i in range(60):
            conn.readline()
