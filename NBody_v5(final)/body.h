#ifndef _NBODY_
#define _NBODY_

#include<stdio.h>
#include<iostream>
//adapted from: http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
//date accessed: 12/6/2018

//creates a custom class in which all of the relevant information is contained. 
//Attributes:
//  Private: m -> the mass of the object; const long double
//             g-> the gravitational constant, will be the same for all bodies; const long double
//  Public: position_x -> position in a x,y cartisian plane; x axis in meters; float
//          position_y -> position in a x,y cartisian plane; y axis in meters; float
//          velocity[2] -> in m/s; [0] = x plane velocity, [1] = y plane velocity; long double array, size 2
//          net_force [2]->recalculated according to first three parameters of each object in timestep;[0] = x plane net force, [1] = y plane net force; float, size 2

//methods: 
//  float get_mass -> retrieve the m
//  float get_gravity -> retrieve g
//  void newton_law_universal_gravitation(Body* b, long double* force); ->calculate the affect of gravitation on the body; defined in body.cpp
//  void update_pos(Body* b, float t) -> update the x and y coordinates of the body; defined in body.cpp
//  void update_pos(Body* b, float t)-> update the x and y velocities of the body; defined in body.cpp
//  void update(Body* b, float t) -> executes the above three functions for streamlining and simplification of main.cpp
//  void where_am_i() -> retrieves and prints out the body's x and y coordinates
class Body
{
    private:
        const long double m = 1.989E10; //mass of the body, in kg
        const long double g = 6.67408E-11; //the gravitational constant, in m3 kg-1 s-2
    public:
        float position_x; // position in a x,y cartisian plane; x axis in meters
        float position_y; // position in a x,y cartisian plane; y axis in meters
	    long double velocity[2];// in m/s; [0] = x plane velocity, [1] = y plane velocity
        float net_force [2]; //recalculated according to first three parameters of each object in timestep;[0] = x plane net force, [1] = y plane net force

    //a get function to retrieve mass
        float get_mass(){
            return m;
        }
    //a get function to retrieve gravity
        float get_gravity(){
            return g;
        }

		void newton_law_universal_gravitation(Body* b, long double* force); //calculate the affect of gravitation on the body

		void update_pos(Body* b, float t); //update the x and y coordinates of the body

		void update_vel(Body* b, float t); //update the x and y velocities of the body; defined in body.cpp


    //the constructor for Body to be used in main
    //Inputs: float p_x -> the x coordinate of the body's position
    //        flaot p_y -> the y coordinate of the body's position
    //Output: None
    //Result: new Body object created with user defined x and y coordinates
        Body(float p_x, float p_y){
            position_x = p_x;
            position_y = p_y;
            velocity[0] = 0.00;
            velocity[1] = 0.00;
        }

		void update(Body* b, float t);//executes the above three functions for streamlining and simplification of main.cpp

    //retrieves and prints out the body's x and y coordinates
        void where_am_i(){
            std::cout << "This is position x: " << position_x <<std::endl;
            std::cout << "This is position y: " <<position_y <<std::endl;
            std::cout <<"\n";
        }


};
#endif
