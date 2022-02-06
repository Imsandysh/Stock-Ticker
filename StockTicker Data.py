
import importlib
from yahoo_fin import stock_info as si
import time
import serial
StockShares = ["TSLA","MRO","KMX","GM", "LYFT", "AAL", "EFC", "EB", "GRUB", "SABR", "DAL"]

ser = serial.Serial('COM12',9600)
def printShare(name):
    price = si.get_live_price(name)
    price = round(price,2)
    strprice = str(price)
    ser.write(str.encode(name + ': *' + strprice))
    print(name + ': *' +strprice)
    time.sleep(.1)
def mainProgram():
    for i in StockShares:
        name = i
        printShare(name)
        importlib.reload(si)
        time.sleep(7)
    mainProgram()
mainProgram()



