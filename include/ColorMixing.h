#ifndef ColorMixing_h
#define ColorMixing_h
#include "Color.h"



class ColorMixing {
private:
	/* data */

public:
	ColorMixing () {};
	Color mix(Color& c1, Color& c2) {
		Color c;
		c.h = mix(c1.h, c2.h, c2.a);
		c.s = mix(c1.s, c2.s, c2.a);
		c.l = mix(c1.l, c2.l, c2.a);
		c.a = max(c1.a, c2.a);
		return c;
	}

	//addes b to a, proportion is the part of b
	double mix(double a, double b, double proportion=0.5){
		return a*(1-proportion) + b*proportion;
	}

	double max(double a, double b){
		if (a > b) return a;
		else return b;
	}

};

ColorMixing const mean_color_mixing;

#endif
