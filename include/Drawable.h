#ifndef Drawable_h
#define Drawable_h

#include "Color.h"
#include "math.h"

class Drawable {
private:

public:
	Drawable () {};
	virtual Color get_color_at_position_at_time(double position, double time) {return opaque;};
	virtual int most_left_index(double time) {return 0;}
	virtual int most_right_index(double time) {return -1;}
	virtual double start_time() {return 0;}
	virtual double end_time() {return -1;}

};

class DrawableWrapper : public Drawable {
protected:
	Drawable* drawable;
public:
	DrawableWrapper (Drawable* drawable_) {drawable = drawable_;};
	Color get_color_at_position_at_time(double position, double time) { return drawable->get_color_at_position_at_time(position, time); };
	int most_left_index(double time) {return drawable->most_left_index(time);}
	int most_right_index(double time) {return drawable->most_right_index(time);}
	double start_time() {return drawable->start_time();}
	double end_time() {return drawable->end_time();}

};


class Moving : public DrawableWrapper {
private:
	/* data */
	double speed, offset;

public:
	Moving (Drawable* drawable_, double speed_, double offset_ = 0) : DrawableWrapper(drawable_) , speed(speed_), offset(offset_) {};
	Color get_color_at_position_at_time(double position, double time) {return drawable->get_color_at_position_at_time(position - speed*time - offset, time);}
	int most_left_index(double time) {
		int left = drawable->most_left_index(time);
		return (int)(left - speed*time - offset) - 1;
	}
	int most_right_index(double time) {
		int right = drawable->most_right_index(time);
		return (int)(right - speed*time - offset) + 1;
	}
};

class Blinking : public DrawableWrapper {
private:
	/* data */
	double period, period_on, delay;
	int times;
	bool restart_time;

public:
	Blinking (Drawable* drawable_, double period_, double period_on_,
		int times_=-1, double delay_ = 0, bool restart_time_=0) : DrawableWrapper(drawable_) , period(period_), period_on(period_on_),
		  delay(delay_), times(times_), restart_time(restart_time_) {};
	Color get_color_at_position_at_time(double position, double time) {
		double local_time = time - delay;
		if (times >= 0 && local_time / period >= times) {return black;}
		if (fmod(local_time, period) > period_on) { return black; }
		if (restart_time) { local_time = fmod(local_time, period); }
		return drawable->get_color_at_position_at_time(position, local_time);
	}
};
#endif
