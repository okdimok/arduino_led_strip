#include "Color.h"
#include "ColorPrint.h"
#include "StripBuffer.h"
#include "Program.h"
#include "Drawables.h"
#include "tests.h"
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

void test_cycles_buffer(){
	Color red(10, 1., 0.6);
	Color orange(40, 1., 0.6);
	StripBuffer strip(60);
	ColorOutput* print = new ColorPrint();
	print->init_output();
	for (int j = 0; j < 1e2; j++) {
		strip.set_uniform(red);
		print->output(strip);
		usleep(1e6/20); //10Hz
		strip.set_uniform(orange);
		print->output(strip);
		usleep(1e6/20);
		printf (" %d", j);
	}
	print->end_output();
}

void test_program(){
	Color red(10, 1., 0.6, 0.7);
	Color orange(40, 1., 0.6, 0.7);
	Color green(100, 1., 0.6, 0.7);
	StripBuffer strip(60);
	ColorOutput* print = new ColorPrint();
	Program p1;
	ColorMixing mean_color_mixing;
	ConstantColorSegment seg1(&strip, &mean_color_mixing, red, 0, 20);
	ConstantColorSegment seg2(&strip, &mean_color_mixing, orange, 10, 40);
	MovingColorSegment seg3(&strip, &mean_color_mixing, green, 30, -10, 3, -3);
	p1.add_drawable(&seg1);
	p1.add_drawable(&seg2);
	p1.add_drawable(&seg3);
	print->init_output();
	double time=0;
	double frequency = 100;
	const double period=1/frequency;
	while (time < 2) {
		strip.clear();
		p1.update_and_draw_all(time);
		print->output(strip);
		time+=period;
		printf(" %g\n", time);
		usleep(1e6*period);
	}
	print->end_output();
}
