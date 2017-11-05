#include <stdio.h>
using namespace std;

class Color {
public:
	double h; //hue, from 0 to 360
	double s; //saturation, from 0 to 1
	double l; //lighting, from 0 to 1
	double a; //opacity, from 0 (completely opaque) to 1
	Color(): h(0), s(0), l(0), a(0)  {};
	Color(double h_, double s_, double l_, double a_=1): h(h_), s(s_), l(l_), a(a_) {report_invalidity();}
	Color(double* hsla) {
		set_from_hsla(hsla);
		report_invalidity();
	}
	void set_from_rgba(double r, double g, double b, double a_=1);
	void set_from_rgba(double* rgba);
	void set_from_hsla(double h, double s, double l, double a_=1);
	void set_from_hsla(double* hsla);
	void get_rgba(double* rgba);
	void get_hsla(double* hsla);
	void print();

	bool report_invalidity();
	bool check_validity();


};
