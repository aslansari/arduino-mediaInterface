from time import sleep

import keyboard
import serial
import portlist

def open_port():
    ports =  portlist.serial_ports()
    ser = serial.Serial()
    ser.baudrate = 9600
    ser.port = ports[1] #COM port that arduino connected to
    ser.open()
    return ser

def main():
    ser = open_port()
    serInt = 0
    while True:
        while ser.inWaiting(): 
            serInput = ser.readline()
            serInput = serInput.decode("UTF-8","ignore")
            splittedResponse = serInput.split('\r\n')
            print (splittedResponse[0])
            try:        #try to parse the message to int
                temp = int(serInput,base=10)
                print ("temp: %s",temp)
                print ("serInt: %s",serInt)
                if (temp<serInt):
                    keyboard.send('Volume_Down', do_press=True, do_release=True)
                    serInt = temp
                elif (temp>serInt):
                    keyboard.send('Volume_Up', do_press=True, do_release=True)
                    serInt = temp        
            except ValueError:
                #
                #   These multimedia keys may vary due to your system. e.g. Media_Next, Next_Track 
                #   can be the same key in different systems
                #
                if splittedResponse[0]=="mute":
                    keyboard.send('Volume_Mute', do_press=True, do_release=True)
                elif splittedResponse[0]=="nextSong":
                    keyboard.send('Next_Track', do_press=True, do_release=True)
                elif splittedResponse[0]=="prevSong":
                    keyboard.send('Previous_Track', do_press=True, do_release=True)
                elif splittedResponse[0]=="playpause":
                    keyboard.send('Play/Pause_Media', do_press=True, do_release=True)
                elif splittedResponse[0]=="spotify": #spotify shortcut key pattern
                    #press key pattern
                    keyboard.send('Ctrl', do_press=True, do_release=False)
                    keyboard.send('Shift', do_press=True, do_release=False)
                    keyboard.send('ü', do_press=True, do_release=False)
                    #release key pattern
                    keyboard.send('Ctrl', do_press=False, do_release=True)
                    keyboard.send('Shift', do_press=False, do_release=True)
                    keyboard.send('ü', do_press=False, do_release=True)
                
            
            
        sleep(.1)

if __name__ == '__main__':
    main()
