include Makefile

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
