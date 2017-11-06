#include "Color.h"
#include "stdio.h"
#include "RGBConverter/RGBConverter.h"

void Color::set_from_rgba(double r, double g, double b, double a_){
	double hsla[4];
	RGBConverter::rgbToHsl(r, g, b, hsla);
	hsla[3] = a_;
	set_from_hsla(hsla);
}

void Color::set_from_rgba(double *rgba){
	set_from_rgba(rgba[0], rgba[1], rgba[2], rgba[2]);
}

void Color::set_from_hsla(double h_, double s_, double l_, double a_){
	h = h_;
	s = s_;
	l = l_;
	a = a_;
}

void Color::set_from_hsla(double* hsla){
	h = hsla[0];
	s = hsla[1];
	l = hsla[2];
	a = hsla[3];
}

void Color::get_hsla(double *hsla){
	hsla[0] = h;
	hsla[1] = s;
	hsla[2] = l;
	hsla[3] = a;
}

void Color::get_rgba(double* rgba){
	RGBConverter::hslToRgb(h, s, l, rgba);
	rgba[3] = a;
}


bool Color::report_invalidity() {
	bool valid = check_validity();
	if (!valid){
		fprintf(stderr, "Bad color: h: %g s: %g l: %g a: %g\n", h, s, l, a);
	}
	return valid;
}

bool Color::check_validity() {
	if (0 > h || 360 < h) return false;
	if (0 > s || 1 < s)   return false;
	if (0 > l || 1 < l)   return false;
	if (0 > a || 1 < a)   return false;
	return true;
}
