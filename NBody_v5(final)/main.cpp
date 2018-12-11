#include"body.h" //add user defined class
#include<iostream> //use for printing coordinates out to console
#include<random> //used for random engine
#include<time.h>
using namespace std;
#define N 10 //the number of celestial bodies to be simulated

//////////////////////////////////////////
// Random int Generation 
// Developed and introduced by Kent Jones 2016
//adapted from: Scott Griffith's LM1_part 4
//accessed: 12/10/2018
//////////////////////////////////////////
random_device rd;	// Used to produce a random seed
default_random_engine engine(rd()); // Use the defualt random number generator engine
std::uniform_real_distribution<> distribution(0, 1000); // Generate a uniform real distribution between 0, 1
//
//Thread-safe C++11 pseudo-random number generator
//@return		returns a random value between 0 and 1
//
double cs273_rand() {
	return distribution(engine);
}
////////////////////////////////////////////
int main(){
    //create an array to hold all of the bodies that will be simulated using this program. The amount depends on N
    Body* objects[N];
    //dynamically allocate memory for body creation. Use the random engine to generate unique coordinates for each body within the coordinates between (0, 1000)
    for(int i = 0; i < N; i++){
        objects[i] = new Body(float(cs273_rand()), float(cs273_rand()));
    }

    // for(int i = 0; i < N; i++){
    //     objects[i] -> where_am_i();
    // }
    // Body* b1 = new Body(20.65, 50.55);
    // Body* b2 = new Body(150.5, 210.35);
    // Body* objects[2];
    // objects[0] = b1;
    // objects[1] = b2;


    const float t = 0.01; //the time step in seconds. Each iteration will increase time passed by this amount. 
    float time_passed = 0.0; //how much time has passed since the simulation has started. This is used for calculating velocity and displacement of each body.

    //for each body in the simulation, calculate the net force, velocity, and position.
for( int i = 0; i < 200000; i++){ //how many timesteps the program will iterate over.
        for(int j = 0; j < N; j++){ // j and k are used to ensure that the body does not do any calculations on itself
            for(int k = 0; k < N; k++){/ j and k are used to ensure that the body does not do any calculations on itself
                if(j != k){ //make sure that the body is not doing calculations on itself
            objects[j]->update(objects[k], t); //update the body's velocity, position, and net force for the current timestep
                }
            }
        time_passed += t; //once all of the bodies have had their velocity, postion, and netforce calculated, increase the time passed by one timestep/
        }
    }

    //For each body, print out the x and y coordinates to the screen using body.h member function where_am_i()
    for(int i = 0; i < N; i++){
        objects[i] -> where_am_i();
        cout << endl;
    }
    return 0;

}
