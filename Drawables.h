#ifndef Drawables_h
#define Drawables_h

#include "StripBuffer.h"
#include "ColorMixing.h"
#include "Drawable.h"

class ConstantColorSegment : public Drawable {
protected:
	Color color;
	unsigned int begin, end;
	void update_and_draw(double time){
		for (unsigned int i = begin; i <= end && i >=0 && i < buffer->length; i++){
			buffer->buffer[i] = color_mixing->mix(buffer->buffer[i], color);
		}
	}
public:
	ConstantColorSegment (StripBuffer* buffer_, ColorMixing* color_mixing_, Color& color_,
		int begin_ = 0, int end_ = -1) : Drawable(buffer_, color_mixing_), color(color_) {
			if (begin_ < 0) {
				begin = buffer->length + begin_;
			} else{
				begin = begin_;
			}
			if (end_ < 0) {
				end = buffer->length + end_;
			}
			else {
				end = end_;
			}
		}
};

#endif
