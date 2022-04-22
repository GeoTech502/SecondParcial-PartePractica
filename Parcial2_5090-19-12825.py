import pyfirmata
import time

DELAY_ROJO = 7
DELAY_AMARILLO = 5
DELAY_VERDE = 7

rgb_verde = 11
Rojo = 3
Amarillo = 4
Verde = 5
pinButton = 2

puerto = 'COM3'

board = pyfirmata.Arduino(puerto)

it = pyfirmata.util.Iterator(board)
it.start()

board.digital[pinButton].mode = pyfirmata.INPUT

board.analog[0].enable_reporting()

for i in range(3):
    board.digital[rgb_verde].write(1)
    time.sleep(0.3)
    board.digital[rgb_verde].write(0)
    time.sleep(0.3)

analogPot = board.get_pin('a:0:i')
led = board.get_pin('d:11:p')

while True: 
    analog = analogPot.read()
    led.write(analog)

    sw = board.digital[pinButton].read()
    if sw is True:
       board.digital[Rojo].write(1)
       board.pass_time(DELAY_ROJO)
       board.digital[Rojo].write(0)
       time.sleep(0.5)
       board.digital[Amarillo].write(1)
       board.pass_time(DELAY_AMARILLO)
       board.digital[Amarillo].write(0)
       time.sleep(0.5)
       board.digital[Verde].write(1)
       board.pass_time(DELAY_VERDE)
       board.digital[Verde].write(0)
       time.sleep(0.5)
    else:
       board.digital[Rojo].write(0)
       board.digital[Amarillo].write(0)
       board.digital[Verde].write(0)
    time.sleep(0)
