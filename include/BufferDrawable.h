#ifndef BufferDrawable_h
#define BufferDrawable_h

#include "StripBuffer.h"
#include "ColorMixing.h"

class BufferDrawable {
protected:
	StripBuffer* buffer;
	ColorMixing* color_mixing;
	virtual void update_and_draw(double time){};
public:
	BufferDrawable() : buffer(NULL), color_mixing(NULL) {}
	BufferDrawable (StripBuffer* buffer_, ColorMixing* color_mixing_) : buffer(buffer_), color_mixing(color_mixing_) {}
	void set_buffer(StripBuffer* buffer_){
		buffer = buffer_;
	}
	void set_color_mixing(ColorMixing* color_mixing_){
		color_mixing = color_mixing_;
	}
	int check_update_and_draw(double time){
		if (buffer && color_mixing) {
			update_and_draw(time);
			return true;
		}
		return false;
	}
};

#endif
