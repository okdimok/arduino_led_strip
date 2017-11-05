#ifndef Drawable_h
#define Drawable_h

#include "StripBuffer.h"
#include "ColorMixing.h"

class Drawable {
protected:
	StripBuffer* buffer;
	ColorMixing* color_mixing;
	virtual void update_and_draw(double time){};
public:
	Drawable() : buffer(NULL), color_mixing(NULL) {}
	Drawable (StripBuffer* buffer_, ColorMixing* color_mixing_) : buffer(buffer_), color_mixing(color_mixing_) {}
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
