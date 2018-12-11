#include"body.h"
#include<iostream>
#include <time.h> //Used by fillRandom to get a variable seed
#include<random>
using namespace std;
#define N 1000

//adapted from: Scott Griffith's LM5 example
//date Accessed: 12/10/2018
__global__ void move(Body *a, float *t){
    int tid = blockIdx.x;
    if(tid < N){
        for(int i =0; i < N; i++){
            if(i != tid){
                a[tid].update(a[i], *t); //void update_pos(Body b, float nf, float t)
            }
        }
    }
}

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

    Body* objects[N];
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


    //Body* result[N]; //Host data, a/b input data, c output data
    Body* dev_a; //Device data pointers for the main data
    float* dev_time; //device data pointer for time

    //Allocate memory on the device
    cudaMalloc( (void**)&dev_a, N*sizeof(Body*));
    //cudaMalloc( (void**)&dev_b, N*sizeof(Body*));
    cudaMalloc( (void**)&dev_time, 1*sizeof(int));

    const float t = 0.01; //the time step in seconds
    float time_passed = 0.0;

    cudaMemcpy(dev_time, time_passed, 1*sizeof(int), cudaMemcpyHostToDevice);
    //add<<<1,100>>>(dev_a, dev_time);

    for( int i = 0; i < 200000; i++){
        cudaMemcpy(dev_a,objects,N*sizeof(Body*),cudaMemcpyHostToDevice);
        move<<<1,1024>>>(dev_a, dev_time);
        cudaMemcpy(objects,dev_a,N*sizeof(Body*),cudaMemcpyDeviceToHost);
        time_passed += t;
        cudaMemcpy(dev_time, time_passed, 1*sizeof(int), cudaMemcpyHostToDevice);
        }

    for(int i = 0; i < N; i++){
        objects[i] -> where_am_i();
        cout << endl;
        
    }
    return 0;
}