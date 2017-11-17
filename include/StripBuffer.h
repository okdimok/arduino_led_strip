#ifndef StripBuffer_h
#define StripBuffer_h

#include "Color.h"

class StripBuffer {
public:
	unsigned int length;
	Color *const buffer;
	StripBuffer(unsigned int length_) : length(length_), buffer(new Color[length_]) {}
	void clear();
	void set_uniform(Color& color){
		for (unsigned int i = 0; i < length; i++){
			buffer[i] = color;
		}
	}
};
#endif
