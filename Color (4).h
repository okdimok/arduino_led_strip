#include <vector>
#include <iostream>
using namespace std;

class Color{
public:
	double h; //hue, from 0 to 360
	double s; //saturation, from 0 to 1
	double l; //lighting, from 0 to 1
	Color(double h_, double s_, double l_): h(h_), s(s_), l(l_) {report_invalidity();}
	Color(vector<double> hsl) {
		h = hsl[0];
		s = hsl[1];
		l = hsl[2];
		report_invalidity();
	}

	bool report_invalidity(){
		if (!check_validity()){
			cerr << "Bad color h:" << h << " s:" << s << " l:" << l << endl;
		}
	}

	bool check_validity(){
		if (0 > h || 360 < h) return false;
		if (0 > s || 1 < s) return false;
		if (0 > l || l < s) return false;
		return true;
	}


};
