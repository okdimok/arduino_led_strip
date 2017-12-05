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
OBJS=$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(subst .cpp,.o,$(SRCS)))



LED_script: $(OBJS)
	@echo $(LD_LIBRARY_PATH)
	$(CC) $(LDFLAGS) -o LED_script $(OBJS) $(LDLIBS) $(INCLUDE_DIRS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

RGBConverter/RGBConverter.o: RGBConverter/RGBConverter.cpp RGBConverter/RGBConverter.h
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDE_DIRS)

test-make:
	@echo SRCS: $(SRCS)
	@echo OBJS: $(OBJS)
	@echo INCLUDE_DIRS: $(INCLUDE_DIRS)

clean::
	rm $(OBJS) LED_script

clean-all: clean LED_script
