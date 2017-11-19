#ifndef Program_h
#define Program_h
#include "StripBuffer.h"
#include "Drawable.h"
#include "BufferDrawable.h"
#include "BufferDrawableDrawable.h"

// This defines a set of time-dependand drawables
#define DRAWABLES_MAX 40

class Program {
private:
	BufferDrawable** drawables;
	unsigned int drawables_number;
	StripBuffer* strip;
public:
	Program(StripBuffer* strip_=NULL) : drawables_number(0), strip(strip_){drawables = new BufferDrawable*[DRAWABLES_MAX];};
	unsigned int add_drawable(BufferDrawable* d) {
		if (drawables_number >= DRAWABLES_MAX) return -1;
		else {
			drawables[drawables_number] = d;
			drawables_number++;
			return drawables_number-1;
		}
	}
	unsigned int add_drawable(Drawable* d, ColorMixing* color_mixing) {
		if (!strip || drawables_number >= DRAWABLES_MAX) return -1;
		BufferDrawableDrawable* bd = new BufferDrawableDrawable(d, strip, color_mixing);
		return add_drawable(bd); //TODO Memory leak!!!
	}
	int update_and_draw_all(double time){
		for (unsigned int i = 0; i < drawables_number; i++){
			drawables[i]->check_update_and_draw(time);
		}
		return drawables_number;
	}


};

#endif
