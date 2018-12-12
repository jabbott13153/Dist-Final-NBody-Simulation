#include <vector>
#include "Graphics.h"

int main(int argc, char* argv[]) {

	std::vector<float> x, y;

	Graphics* Represent = new Graphics(5, x, y, argc, argv);

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 5; j++) {
			x.push_back(float((j)*5));
			y.push_back(float((j)*5));
		}

		Represent->update_coords(x, y);
		Represent->redraw_call(argc, argv);

		x.clear();
		y.clear();

		for (int j = 0; j < 5; j++) {
			x.push_back(float((j)*3));
			y.push_back(float((j)*3));
		}

		Represent->update_coords(x, y);
		Represent->redraw_call(argc, argv);

		x.clear();
		y.clear();
	}

	return 0; 
	
}