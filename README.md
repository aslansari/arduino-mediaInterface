# arduino-mediaInterface
  Multimedia keypad interface, using hid incompatible arduino boards like arduino nano, pro-mini, uno(with serial interface)

# Auto-start (Currently just for windows)
  If you don't want to start manually everytime after boot up, you need to copy the vbs file to the startup folder. You need to specify the full path of the batch file in vbs file.
  In batch file you need to update the path of the comread python file in order to make things work. 
  
# Com-port
Portlist code returns list of existing ports. You should plug arduino and check which port its connected to. In comread file default port is the second port, if its not the case in your system you need to change the parameter of ports[] array in open_port() function
