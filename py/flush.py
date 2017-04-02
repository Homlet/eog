import serial

conn = serial.Serial("/dev/cu.usbmodem1411", 9600)
while True:
    conn.readline()
    
