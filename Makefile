CPPFLAGS=-g -Wall
LDFLAGS=-g
LDLIBS=-lm
CC=g++
# INCLUDE_DIRS=-I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/cores/arduino -I/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/include -I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/variants/leonardo
SRCS=$(wildcard *.cpp) RGBConverter/RGBConverter.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
# MCU = atmega2560
# CPPFLAGS += -mmcu=$(MCU)

BOARD_TAG     = mega2560
MONITOR_PORT  = /dev/ttyACM0
# include $(ARDMK_DIR)/Arduino.mk




LED_script: $(OBJS)
	echo $(OBJS)
	$(CC) $(LDFLAGS) -o LED_script $(OBJS) $(LDLIBS)



%.o: %.cpp %.h
	$(CC) $(CPPFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	rm $(OBJS) LED_script

clean-all: clean LED_script
