#pragma once
#ifndef GRAPHICS_H_
#define GRAPHICS_H_

/*NOTE that for this code to compile you must have freeglut and properly configure it for VS!!*/
#include <GL/freeglut.h> //Include to use freeglut library for easier OpenGL functions. (must link librarys to use!!!)
#include <GL/gl.h>       //Include for OpenGL functionality.
#include <vector>
#include <chrono>

//Variables need to be either global or in main to work with glut.... I'll leave them here in the h file for now.
int Num_Particles;     //Number of particles in simulation.
std::vector<float> x;  //Vector of x positions (MAY NOT WORK WITH LARGE AMOUNTS OF POINTS!!! If that happens we need to malloc some space).
std::vector<float> y;  //Vector of y positions (Same warning as above).

//This function MUST be global (outside the class) for glut to work, it will not work if the function is associated with the class itself
//DO NOT MOVE INTO THE CLASS. Or at least find some way for it to work there....
void draw_particles() {                //Function to draw particles.
	glPointSize(3.0);                  //Set size of particles to some value.
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set clear screen stats for clear function.
	glClear(GL_COLOR_BUFFER_BIT);      //Clear the screen and put in the clear color.
	glColor3f(1.0, 1.0, 1.0);          //Color for the particles?

	glBegin(GL_POINTS);                //Begin the process and let the program draw points.

	for (int i = 0; i < Num_Particles; i++) {
		glVertex2f(x[i], y[i]);        //Set location to draw point in 2D with floats.
	}

	glutPostRedisplay();               //Refer to the already initialized graphics and update the data.
	glEnd();                           //End process of drawing.
	glFlush();                         //Clean up OpenGL stuff.
};

class Graphics{
public:

	Graphics(int Temp_Particles, std::vector<float> temp_x, std::vector<float> temp_y, int arg1, char **arg2){ //Takes in the number of particles and main() arguments.
		Num_Particles = Temp_Particles;   //Set number of particles.
		x = temp_x;                       //Initialize x and y just so the program is happy.
		y = temp_y;

		glutInit(&arg1, arg2);                           //Initialize glut.
		glutInitDisplayMode(GLUT_SINGLE);                //Set display mode.
		glutInitWindowSize(500, 500);                    //Window size.
		glutInitWindowPosition(100, 100);                //Window position.
		glutCreateWindow("OpenGL - N-body Simulation");  //Create the window with this name.
		glMatrixMode(GL_PROJECTION);                     //coordinate system
		gluOrtho2D(-100.0, 100.0, -100.0, 100.0);        //Readjust this for a reasonable x,y plane!
	};


	//Update the coordinate vectors.
	void update_coords(std::vector<float> temp_x, std::vector<float> temp_y) {
		x = temp_x;
		y = temp_y;
	};

	void redraw_call(int arg1, char **arg2) {  //Redraw the graphic (update after change to x/y).
		glutDisplayFunc(draw_particles);       //Refer to the function for the drawing instructions.
		glutMainLoopEvent();                   //Event processing loop, only called once.
		Sleep(100);                            //Adjust this for the refresh rate.
	}
};

#endif