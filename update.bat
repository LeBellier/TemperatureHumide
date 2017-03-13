python.exe "D:\Bruno\Documents\ArduinoData\packages\esp8266\hardware\esp8266\2.3.0\tools\espota.py" -i 192.168.1.20 -f "D:\Bruno\Documents\GitHub\LEDTable\CodeArduino\ESPTable\Release\ESPTable.bin" --auth=123  -d True -r True
pause REM Fin de la pause lorsque la led est eteinte!
telnet 192.168.1.20
pause