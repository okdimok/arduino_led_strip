#include "ColorOutput.h"
#include <stdio.h>


class ColorPrint : public ColorOutput{
public:
	ColorPrint(){}

	void output(Color& color){
		double rgba[4];
		color.get_rgba(rgba);
		int r = rgba[0], g = rgba[1], b = rgba[2];
		printf("\e[38;2;%d;%d;%dm▀", r, g, b); //add 48;2;0;0;0 for backgroud
	}

	void init_output(){
		printf("\e[?25l"); //cursor off
	}
	void init_buffer_output(){
		printf ("\r ");
	}
	void end_buffer_output(){
		fflush(stdout);
	}
	void end_output(){
		printf("\e[?25h\n"); //cursor on, newline
	}
};
