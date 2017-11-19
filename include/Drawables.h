#ifndef Drawables_h
#define Drawables_h

#include "Drawable.h"
#include "Color.h"
#include "TimeDependantColor.h"

class ColorSegment : public Drawable {
private:
	/* data */
	TimeDependantColor* tc;
	double left, right;

public:
	ColorSegment (TimeDependantColor* tc_, double left_, double right_) :
		tc(tc_), left(left_), right(right_) {};
	Color get_color_at_position_at_time(double position, double time) {
		if (position > left && position < right) return tc->get_color(time);
		else return opaque;
	}
};

#endif
