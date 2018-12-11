#ifndef _NBODY_
#define _NBODY_

#include<stdio.h>
#include<iostream>
//adapted from: http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
//date accessed: 12/6/2018
class Body
{
    private:
        const long double m = 1.989E10; //mass of the sun, in kg
        const long double g = 6.67408E-11; //the gravitational constant, in m3 kg-1 s-2
    public:
        float position_x; // position in a x,y cartisian plane; [0] = x, [1] = y; in meters(?)
        float position_y;
        // float velocity_x; // in m/s; [0] = x plane velocity, [1] = y plan velocity
        // float velocity_y;
		long double velocity[2];
        float net_force [2]; //recalculated according to first three parameters of each object in timestep
		//long double accel[2];

        float get_mass(){
            return m;
        }

        float get_gravity(){
            return g;
        }

		void newton_law_universal_gravitation(Body* b, long double* force); //calculate the affect of gravitation on the body

		void update_pos(Body* b, float t); //update the x and y coordinates of the body

		void update_vel(Body* b, float t);

//		long double* calc_velocity(Body* b, float t, float delta_t, long double* force); //calculate the velocity
    
//		long double* calc_accel(Body* b, float t, float delta_t); // calculate the acceleration 

        Body(float p_x, float p_y){
            position_x = p_x;
            position_y = p_y;
            velocity[0] = 0.00;
            velocity[1] = 0.00;
        }

		void update(Body* b, float t);

        void where_am_i(){
            std::cout << "This is position x: " << position_x <<std::endl;
            std::cout << "This is position y: " <<position_y <<std::endl;
            std::cout <<"\n";
        }


};
#endif