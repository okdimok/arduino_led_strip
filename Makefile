CPPFLAGS=-Wall
LDFLAGS=
LDLIBS=
CC=g++
INCLUDE_DIRS=


SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj

INCLUDE_DIRS+= -I.
INCLUDE_DIRS+= -I./$(INC_DIR)

SRCS=$(wildcard $(SRC_DIR)/*.cpp) RGBConverter/RGBConverter.cpp
OBJS=$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(subst .cpp,.o,$(SRCS)))



LED_script: $(OBJS)
	@echo $(LD_LIBRARY_PATH)
	$(CC) $(LDFLAGS) -o LED_script $(OBJS) $(LDLIBS) $(INCLUDE_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CC) $(CPPFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

RGBConverter/RGBConverter.o: RGBConverter/RGBConverter.cpp RGBConverter/RGBConverter.h
	$(CC) $(CPPFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

test-make:
	@echo SRCS: $(SRCS)
	@echo OBJS: $(OBJS)
	@echo INCLUDE_DIRS: $(INCLUDE_DIRS)

clean::
	rm $(OBJS) LED_script

clean-all: clean LED_script



# MCU = atmega2560
# CPPFLAGS += -mmcu=$(MCU)
# LDFLAGS += -mmcu=$(MCU)
#
# CC=avr-g++
# BOARD_TAG     = mega2560
# MONITOR_PORT  = /dev/ttyACM0
# INCLUDE_DIRS+=-I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/cores/arduino -I/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/include -I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/variants/leonardo
# LDLIBS+= -L/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/lib/avr6 -latmega2560 -lc
#
# LOCAL_CPP_SRCS=$(SRCS)
# LOCAL_INO_SRCS=$(wildcard $(SRC_DIR)/*.ino)
# AVR_TOOLS_DIR = /usr
# include $(ARDMK_DIR)/Arduino.mk

# @echo $(OBJS)
# @echo target: $@, prerequisites: $^
