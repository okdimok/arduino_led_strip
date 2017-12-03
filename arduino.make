include Makefile
# MCU = atmega2560
# CPPFLAGS += -mmcu=$(MCU)
# LDFLAGS += -mmcu=$(MCU)

CC=avr-g++
BOARD_TAG    = mega
BOARD_SUB    = atmega2560
MONITOR_PORT  = /dev/tty_arduino_led
# INCLUDE_DIRS+=-I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/cores/arduino -I/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/include -I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/variants/leonardo
LDLIBS+= -L/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/lib/avr6 -latmega2560 -lc

LOCAL_CPP_SRCS=$(SRCS)
LOCAL_INO_SRCS=$(wildcard $(SRC_DIR)/*.ino)
CPPFLAGS += $(INCLUDE_DIRS)
AVR_TOOLS_DIR =  /home/dima/apps/arduino-1.8.1/hardware/tools/avr
AVRDUDE_CONF = /home/dima/apps/arduino-1.8.1/hardware/tools/avr/etc/avrdude.conf
# F_CPU=8000000L
F_CPU=16000000L
MAKE=make -f arduino.make
include $(ARDMK_DIR)/Arduino.mk

# @echo $(OBJS)
# @echo target: $@, prerequisites: $^
