CPPFLAGS=-Wall
LDFLAGS=
LDLIBS=-lm
CC=g++
INCLUDE_DIRS=
# INCLUDE_DIRS+=-I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/cores/arduino -I/home/dima/apps/arduino-1.8.1/hardware/tools/avr/avr/include -I/home/dima/apps/arduino-1.8.1/hardware/arduino/avr/variants/leonardo

SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj

INCLUDE_DIRS+= -I.
INCLUDE_DIRS+= -I./$(INC_DIR)

SRCS=$(wildcard $(SRC_DIR)/*.cpp) RGBConverter/RGBConverter.cpp
OBJS=$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(subst .cpp,.o,$(SRCS)))
# MCU = atmega2560
# CPPFLAGS += -mmcu=$(MCU)

BOARD_TAG     = mega2560
MONITOR_PORT  = /dev/ttyACM0
# include $(ARDMK_DIR)/Arduino.mk

LED_script: $(OBJS)
	# @echo $(OBJS)
	$(CC) $(LDFLAGS) -o LED_script $(OBJS) $(LDLIBS) $(INCLUDE_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	# @echo target: $@, prerequisites: $^
	$(CC) $(CPPFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

test-make:
	@echo SRCS: $(SRCS)
	@echo OBJS: $(OBJS)
	@echo INCLUDE_DIRS: $(INCLUDE_DIRS)

clean:
	rm $(OBJS) LED_script

clean-all: clean LED_script
