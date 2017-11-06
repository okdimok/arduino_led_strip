#include "StripBuffer.h"

void StripBuffer::clear(){
	for (int unsigned i = 0; i < this->length; i++){
		buffer[i]=black;
	}
}
