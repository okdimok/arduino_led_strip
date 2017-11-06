#ifndef TimeDependantColor_h
#define TimeDependantColor_h

class TimeDependantColor {
private:
	/* data */

public:
	TimeDependantColor ();
	virtual Color get_color(double time){};
	// virtual ~TimeDependantColor ();
};
#endif
