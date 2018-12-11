#include"body.h"
#include<math.h>
#include<cmath>
//adapted from: http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
//date accessed: 12/6/2018
void Body::newton_law_universal_gravitation(Body* b, long double* force){ //Body = star we are calculating, t is the timestep
    long double r1_r2[2]; //vector r1 minus vector r2
    //float g = 6.67408E-11;
    //float m = 1.989E30;
    r1_r2[0] = position_x - b -> position_x;
    r1_r2[1] = position_y - b ->position_y;
    long double r12 = sqrt(pow((position_x - b -> position_x),2) + pow((position_y - b -> position_y), 2)); //get the distance between the stars
    //float F12[2];
    long double f12_x = g*((m * b -> m)/abs(pow(r12, 3))) * r1_r2[0]; //the equation to get the force between two bodies, this is the same for both bodies
    long double f12_y = g*((m * b -> m)/abs(pow(r12, 3))) * r1_r2[1]; //the equation to get the force between two bodies, this is the same for both bodies
	net_force[0] = abs(f12_x);
	net_force[1] = abs(f12_y);
    
}


//adapted from: http://zonalandeducation.com/mstm/physics/mechanics/forces/newton/mightyFEqMA/mightyFEqMA.html
//date accessed: 12/10/2018
void Body::update_pos(Body* b, float t) {
	long double d1_x; //the displacement of the body in the x plane
	long double d1_y; //the displacement of the body in the y plane
	d1_x = velocity[0] * t + (.5)*(net_force[0]/ m)*(t*t); //calculate the displacement in the x plane (v = current velocity, F = current force, m = body's mass, t = current time)
	d1_y = velocity[1] * t + (.5)*(net_force[1] / m)*(t*t); //calculate the displacement in the y plane (v = current velocity, F = current force, m = body's mass, t = current time)
	position_x += float(d1_x); //update body's x position
	position_y += float(d1_y); //update body's y position
}

void Body::update_vel(Body * b, float t)
{
	long double v_x = velocity[0] + (net_force[0] / m)*t; //calculating the velocity of the body (of the next timestep) in the x plane
	long double v_y = velocity[1] + (net_force[1] / m)*t; //calculating the velocity of the body (of the next timestep) in the y plane
	velocity[0] = v_x; //update body's velocity
	velocity[1] = v_y; //update body's velocity
	
}

void Body::update(Body * b, float t)
{
	long double force[2];
	newton_law_universal_gravitation(b, force);
	update_pos(b, t);
	update_vel(b, t);
}
