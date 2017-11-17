#ifndef Drawable_h
#define Drawable_h
class Drawable {
private:

public:
	Drawable ();
	virtual Color get_color_at_position_at_time(double position, double time);
	virtual int most_left_index() {return 0;}
	virtual int most_right_index() {return -1;}

};

class Moving : public Drawable {
private:
	/* data */
	Drawable* drawable;
	double speed, offset;

public:
	Moving (Drawable* drawable_, double speed_, double offset_ = 0) : drawable(drawable_) , speed(speed_), offset(offset_) {};
	Color get_color_at_position_at_time(double position, double time) {return drawable->get_color_at_position_at_time(position - speed*time - offset, time);}
};

class Blinking : public Drawable {
private:
	/* data */
	Drawable* drawable;
	double period, period_on, delay;
	int times;
	bool restart_time;

public:
	Blinking (Drawable* drawable_, double period_, double period_on_,
		int times_=-1, double delay_ = 0, bool restart_time_=0) : drawable(drawable_) , period(period_), period_on(period_on_),
		 times(times_), delay(delay_), restart_time(restart_time_) {};
	Color get_color_at_position_at_time(double position, double time) {
		double local_time = time - delay;
		if (times >= 0 && local_time / period >= times) {return black;}
		if (local_time % period > period_on) { return black; }
		if (restart_time) { local_time %= period; }
		return drawable->get_color_at_position_at_time(position - speed*time - offset, local_time);
	}
};
#endif
