#ifndef ColorOutput_h
#define ColorOutput_h

#include "Color.h"
#include "StripBuffer.h"


class ColorOutput {
public:
	ColorOutput(){}
	void init_output(){}
	void init_buffer_output(){}
	virtual void output(Color& color){}
	void output(StripBuffer& buffer){
		for (unsigned int i = 0; i < buffer.length; i++){
			output(buffer.buffer[i]);
		}
	}
	void end_buffer_output(){}
	void end_output(){}
};

#endif
