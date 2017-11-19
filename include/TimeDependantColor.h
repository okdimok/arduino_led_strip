#ifndef TimeDependantColor_h
#define TimeDependantColor_h

#include "Color.h"

class TimeDependantColor {
private:
	/* data */
public:
	TimeDependantColor (){};
	virtual Color get_color(double time){return opaque;};
	// virtual ~TimeDependantColor ();
};

class ConstantTimeDependantColor : public TimeDependantColor {
private:
	/* data */
	Color primary_color;

public:
	ConstantTimeDependantColor () : primary_color(black) {};
	ConstantTimeDependantColor (Color& color) {primary_color = color;}
	virtual Color get_color(double time){return primary_color; };
	// virtual ~TimeDependantColor ();
};

#endif
