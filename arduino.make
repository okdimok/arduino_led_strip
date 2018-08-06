include Makefile
# MCU = atmega2560
# CPPFLAGS += -mmcu=$(MCU)
# LDFLAGS += -mmcu=$(MCU)

# CC=avr-g++
# BOARD_TAG    = mega
# BOARD_SUB    = atmega2560
# MONITOR_PORT  = /dev/tty_arduino_led

BOARD_TAG = uno
MONITOR_PORT  = /dev/ttyUSB1

# INCLUDE_DIRS+=-I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/cores/arduino -I/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/include -I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/variants/leonardo
LDLIBS+= -L/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/lib/avr6 -latmega2560 -lc

LOCAL_CPP_SRCS=$(SRCS)
LOCAL_INO_SRCS=$(wildcard $(SRC_DIR)/*.ino)
CPPFLAGS += $(INCLUDE_DIRS) -Wextra -g
LDFLAGS += -Wl,--relax
LDFLAGS += -flto -fuse-linker-plugin
AVR_TOOLS_DIR =  /home/dima/apps/arduino-1.8.1/hardware/tools/avr
AVRDUDE_CONF = /home/dima/apps/arduino-1.8.1/hardware/tools/avr/etc/avrdude.conf
AVRDUDE_OPTS= -v
# F_CPU=8000000L
F_CPU=16000000L
ARDUINO_VERSION = 10801
CPPFLAGS += -DARDUINO_AVR_MEGA2560
#CPPFLAGS += -flto
CFLAGS += -fno-fat-lto-objects
CFLAGS += --std=gnu11
CXXFLAGS += -fpermissive
CXXFLAGS += -fno-threadsafe-statics
AR_NAME = avr-gcc-ar
MAKE=make -f arduino.make
include $(ARDMK_DIR)/Arduino.mk

# @echo $(OBJS)
# @echo target: $@, prerequisites: $^
