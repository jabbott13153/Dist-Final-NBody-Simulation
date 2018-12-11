#include"body.h"
#include<math.h>

float* Body::newton_law_universal_gravitation(Body* b, float t, float* force){ //Body = star we are calculating, t is the timestep
    float r1_r2[2]; //vector r1 minus vector r2
    //float g = 6.67408E-11;
    //float m = 1.989E30;
    r1_r2[0] = position_x - b -> position_x;
    r1_r2[1] = position_y - b ->position_y;
    float r12 = sqrt(pow((position_x - b -> position_x),2) + pow((position_y - b -> position_y), 2.0)); //get the distance between the stars
    //float F12[2];
    //float f12_x = g*((m * b -> m)/abs(pow(r12, 3))) * r1_r2[0]; //the equation to get the force between two bodies, this is the same for both bodies
    float f12_x = 1;
    *force = f12_x;
    //float f12_y = g*((m * b -> m)/abs(pow(r12, 3))) * r1_r2[0]; //the equation to get the force between two bodies, this is the same for both bodies
    float f12_y = 2;
    *(force+1) = f12_y;
    printf("This is [0]: %f\n", *force);
    printf("This is [1]: %f\n", *(force+1));
    printf("We're calculating newton's law\n");
    return force;
}

float* Body::calc_velocity(Body* b, float t, float* force){ //calculate the velocity
    printf("Starting velocity calc, lhs\n");
    float blegh[2];
    float* lhs = Body::newton_law_universal_gravitation(b, t + t, blegh);
    printf("Starting velocity calc, rhs\n");
    float* rhs = Body::newton_law_universal_gravitation(b, t, blegh);
    printf("finished call to newtorn's law\n");
    float xval = *lhs - *rhs;
    printf("Finished subtraction math xval\n");
    float yval = lhs[1] - rhs[1];
    printf("Finished subtraction math yval\n"); 
    *force = xval;
    *(force +1) = yval;
    /*
    float x_val = 
    temp = Body::newton_law_universal_gravitation(b, t + t) - Body::newton_law_universal_gravitation(b, t);
    return temp;
    */
   printf("We've finished calculating the velocity\n");
   return force;
}
    
float* Body::calc_accel(Body* b, float t){ // calculate the acceleration 
    float temp[2];
    float * lhs = (calc_velocity(b, t +t, temp));
    float * rhs = (calc_velocity(b, t, temp));
    float xval = (t+t) * lhs[0] - rhs[0] *t;
    float yval = (t+t) * lhs[1] - rhs[1] *t;
    //float* temp = (t+t) * (calc_velocity(b, t +t)) - (calc_velocity(b, t)) * t;

    float total[2];
    total[0] = xval;
    total[1] = yval;

    printf("We're calculating the acceleration\n");
    return total;
    
}