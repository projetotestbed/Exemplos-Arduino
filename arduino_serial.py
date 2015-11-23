import serial
import time
import fileinput
import sys
import urllib

port = 'socket://146.164.247.210:'
print "Digite a porta para comunicacao"
porta = sys.stdin.readline()

port_name = port + porta

print "Inicializando porta serial...\n"

arduino = serial.serial_for_url(port_name,115200)
arduino.setTimeout(20)

time.sleep(2) # Esperando inicializacao
print "Pronto para entrada\n"

while 1:
	key = sys.stdin.read(1)
	if ord(key[0]) is 10: continue
	
	arduino.write(key) # Envia tecla digitada para o arduino
	
	print arduino.readline() # Le o que foi escrito pelo arduino
	
