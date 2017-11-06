#ifndef ColorTimeGradient_h
#define ColorTimeGradient_h

#include "TimeDependantColor.h"
#include "ColorMixer.h"
#include "Color.h"

class ColorTimeGradient : public TimeDependantColor{
private:
	/* data */
	Color** colors;
	double period;
	unsigned int colors_length;
	double phase_period;
	ColorMixer* color_mixer;

public:
	ColorTimeGradient (Color** colors_, unsigned int colors_length_, double period_, ColorMixer* color_mixer_): colors(colors_), colors_length(colors_length_),
	 period(period_), color_mixer(color_mixer_){
		phase_period = period/colors_length;
	};
	virtual Color get_color(double time){
		double t0 = time % period;
		unsigned int phase = t0 / phase_period;
		proportion = (t0 - phase * phase_period) / phase_period;
		if (phase < colors_length - 1){
			return color_mixer.mix(colors[phase], colors[phase+1], proportion);
		} else {
			return color_mixer.mix(colors[colors_length - 1 ], colors[0], proportion);
		}
	};
	// virtual ~ColorTimeGradient ();
};
#endif
