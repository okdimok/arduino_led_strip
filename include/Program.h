#ifndef Program_h
#define Program_h
#include "StripBuffer.h"
#include "Drawable.h"

// This defines a set of time-dependand drawables
#define DRAWABLES_MAX 40

class Program {
private:
	Drawable ** drawables;
	unsigned int drawables_number;
public:
	Program() : drawables_number(0) {drawables = new Drawable*[DRAWABLES_MAX];};
	unsigned int add_drawable(Drawable* d) {
		if (drawables_number >= DRAWABLES_MAX) return -1;
		else {
			drawables[drawables_number] = d;
			drawables_number++;
			return drawables_number-1;
		}
	}
	int update_and_draw_all(double time){
		for (unsigned int i = 0; i < drawables_number; i++){
			drawables[i]->check_update_and_draw(time);
		}
		return drawables_number;
	}


};

#endif
