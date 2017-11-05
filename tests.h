#include "Color.h"
#include "ColorPrint.h"
#include <unistd.h> //usleep

void test_color(){
	Color red(10, 1., 0.6);
	Color orange(40, 1., 0.6);
	Color strange(-1, 1., 2);
	Color ff;
	ff.set_from_rgba(255, 0, 0, 0);
}

void test_cycles(){
	Color red(10, 1., 0.6);
	Color orange(40, 1., 0.6);
	Color strange(-1, 1., 2);
	Color ff;
	ff.set_from_rgba(255, 0, 0, 0);
	ColorPrint print;
	print.init_output();
	print.output(ff);

	for (int j = 0; j < 1e2; j++) {
		print.init_buffer_output();
		for (int i = 0; i<20; i++) print.output(orange);
		print.end_buffer_output();
		usleep(1e6/20); //10Hz
		print.init_buffer_output();
		for (int i = 0; i<20; i++) print.output(red);
		print.end_buffer_output();
		usleep(1e6/20);
		printf (" %d", j);
	}
	print.end_output();
}
