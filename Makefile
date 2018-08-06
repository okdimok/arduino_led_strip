CXXFLAGS=-Wall -std=gnu++11
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
#SRCS=src/Color.cpp src/ColorPosition.cpp src/Program.cpp src/StripBuffer.cpp src/BufferDrawables.cpp src/BufferDrawableDrawable.cpp src/tests.cpp RGBConverter/RGBConverter.cpp src/LED_script.cpp
OBJS=$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(subst .cpp,.o,$(SRCS)))
