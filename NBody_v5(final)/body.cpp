#include"body.h"
#include<math.h>
#include<cmath>
//adapted from: http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
//date accessed: 12/6/2018

//this funciton calculates the net force acting on a body on both the x and y axis. It then updates the body's position
//Inputs: Body *b -> the second body that we are currently doing calculations on
	//long double* force -> not used, needs to be removed
//Outputs: None
//Result: the body's net_force attribute is updated for the current timestep
void Body::newton_law_universal_gravitation(Body* b, long double* force){ 
    long double r1_r2[2]; //vector r1 minus vector r2
    r1_r2[0] = position_x - b -> position_x; //calculate the x axis vector (x1 - x2)
    r1_r2[1] = position_y - b ->position_y; //calculate the y axis vector(y1 - y2)
    long double r12 = sqrt(pow((position_x - b -> position_x),2) + pow((position_y - b -> position_y), 2)); //get the distance between the stars
    //float F12[2];
    long double f12_x = g*((m * b -> m)/abs(pow(r12, 3))) * r1_r2[0]; //the equation to get the force between two bodies, this is the same for both bodies
    long double f12_y = g*((m * b -> m)/abs(pow(r12, 3))) * r1_r2[1]; //the equation to get the force between two bodies, this is the same for both bodies
	net_force[0] = abs(f12_x); //update the net force of the x axis
	net_force[1] = abs(f12_y); //update the net force of the y axis
    
}


//adapted from: http://zonalandeducation.com/mstm/physics/mechanics/forces/newton/mightyFEqMA/mightyFEqMA.html
//date accessed: 12/10/2018

//this function updates the body's postion in the cartisian coordinate grid. It implements the formula: d = vt + (1/2)at^2, where v is the current velocity, t is the current timestep, a is the acceleration (Here calculated using Force/mass), and d is the displacement from the current position
//Inputs: Body * b -> The second body that is being acted upon, not used in this calculation
//    t -> the current timestep
//Outputs: None
//Result: the position_x and position_y attributes of body are updated
void Body::update_pos(Body* b, float t) {
	long double d1_x; //the displacement of the body in the x plane
	long double d1_y; //the displacement of the body in the y plane
	d1_x = velocity[0] * t + (.5)*(net_force[0]/ m)*(t*t); //calculate the displacement in the x plane (v = current velocity, F = current force, m = body's mass, t = current time)
	d1_y = velocity[1] * t + (.5)*(net_force[1] / m)*(t*t); //calculate the displacement in the y plane (v = current velocity, F = current force, m = body's mass, t = current time)
	position_x += float(d1_x); //update body's x position
	position_y += float(d1_y); //update body's y position
}


//this function updates the body's velocity in the cartisian coordinate grid. It implements the formula: vf = vi*at, where v is the current velocity, t is the current timestep, a is the acceleration (Here calculated using Force/mass), and vf is the new velocity.
//Inputs: Body * b -> The second body that is being acted upon, not used in this calculation
//    t -> the current timestep
//Outputs: None
//Result: the velocity attribute of body is updated
void Body::update_vel(Body * b, float t)
{
	long double v_x = velocity[0] + (net_force[0] / m)*t; //calculating the velocity of the body (of the next timestep) in the x plane
	long double v_y = velocity[1] + (net_force[1] / m)*t; //calculating the velocity of the body (of the next timestep) in the y plane
	velocity[0] = v_x; //update body's velocity
	velocity[1] = v_y; //update body's velocity
	
}

//This function takes the previous three methods and uses them sequentially in order to simplify the code in main.cpp, and to streamline the process of updating each body's positon
//Inputs: Body * b -> The second body that is being acted upon, used in newton_law_universal_gravitation
//    t -> the current timestep, used in all three methods
//Ouputs: None
//Result: All of the relevent information is updated for the body 
void Body::update(Body * b, float t)
{
	long double force[2];
	newton_law_universal_gravitation(b, force);
	update_pos(b, t);
	update_vel(b, t);
}
