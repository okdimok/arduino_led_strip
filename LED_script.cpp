#include "Color.h"
#include <unistd.h>


using namespace std;

int main(int argc, char** argv){
	Color red(10, 1., 0.6);
	Color orange(40, 1., 0.6);
	Color strange(-1, 1., 2);
	Color ff;
	ff.set_from_rgba(255, 0, 0, 0);
	ff.print();
	 printf("\e[?25l"); //cursor off

	for (int j = 0; j < 1e2; j++) {
		printf("\r ");
		for (int i = 0; i<20; i++) orange.print();
		fflush(stdout);
		usleep(1e5); //100Hz
		printf("\r ");
		for (int i = 0; i<20; i++) red.print();
		fflush(stdout);
		usleep(1e5);
	}
	printf("\e[?25h"); //cursor on

	printf("\n");

}
