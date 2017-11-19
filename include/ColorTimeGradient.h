#ifndef ColorTimeGradient_h
#define ColorTimeGradient_h

#include "TimeDependantColor.h"
#include "ColorMixing.h"
#include "Color.h"

class ColorTimeGradient : public TimeDependantColor{
private:
	/* data */
	Color** colors;
	double period;
	unsigned int colors_length;
	double phase_period;
	ColorMixing* color_mixing;

public:
	ColorTimeGradient (Color** colors_, unsigned int colors_length_, double period_, ColorMixing* color_mixing_=NULL): colors(colors_), colors_length(colors_length_),
	 period(period_){
		if (color_mixing_) color_mixing = color_mixing_;
		else color_mixing = mean_color_mixing;
		phase_period = period/colors_length;
	};
	virtual Color get_color(double time){
		double t0 = time % period;
		unsigned int phase = t0 / phase_period;
		proportion = (t0 - phase * phase_period) / phase_period;
		if (phase < colors_length - 1){
			return color_mixing.mix(colors[phase], colors[phase+1], proportion);
		} else {
			return color_mixing.mix(colors[colors_length - 1 ], colors[0], proportion);
		}
	};
	// virtual ~ColorTimeGradient ();
};
#endif
