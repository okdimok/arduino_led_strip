#ifndef ColorMixing_h
#define ColorMixing_h
#include "Color.h"



class ColorMixing {
private:
	/* data */

public:
	ColorMixing () {};
	Color mix(Color& c1, Color& c2, double proportion=-1) {
		Color c;
		double new_part = c2.a;
		if (proportion >= 0 && proportion <= 1 ) new_part = proportion;
		c.h = mix(c1.h, c2.h, new_part);
		c.s = mix(c1.s, c2.s, new_part);
		c.l = mix(c1.l, c2.l, new_part);
		c.a = max(c1.a, c2.a);
		if (proportion >= 0 && proportion <= 1 ) c.a = mix(c1.a, c2.a, proportion);
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
