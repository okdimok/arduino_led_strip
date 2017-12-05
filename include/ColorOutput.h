#ifndef ColorOutput_h
#define ColorOutput_h

#include "Color.h"
#include "StripBuffer.h"


class ColorOutput {
public:
	ColorOutput(){}
	virtual void init_output(){}
	virtual void init_buffer_output(){}
	virtual void output(Color& color){(void) color;}
	void output(StripBuffer& buffer){
		this->init_buffer_output();
		for (unsigned int i = 0; i < buffer.length; i++){
			output(buffer.buffer[i]);
		}
		this->end_buffer_output();
	}
	virtual void end_buffer_output(){}
	virtual void end_output(){}
};

#endif
