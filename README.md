# Dist-Final-NBody-Simulation
An NBody gravitational simulation utilizing c++

# Calculations and Backend
## Design Overview
This program simulates the physics of N stars upon eachother, with the only force being that which is exerted upon the stars by eachother.  
  - Main.cpp takes care of all of the actual allocating of memory and executing of methods. First, `#define N` defines how many stars(Bodies) the program will be simulating the physics of. It then creates a random number generator that creates a float between (1, 1000). Next, the program dynamically creates N pointer objects of the custom class Body, with each object having their positions being initialized using the random engine. `const float t` defines the timestep that the program will be using, and `time_passed`, a float that keeps track of how many timesteps have passed (in the form of a cumulative sum) during the execution of the program. A nested loop is defined with the variables `i`, `j`, and `k`. `i` keeps track of how many timesteps total the program will go through before terminating, and `j` and `k` make sure that no Body does any calculations on itself. This would lead to an incorrect result at the end of the program. Inside of all three nested loops, each body calculates its position, velocity, and net force relative to every other body the program is simulating. Inside of the `i` loop only, the `time_passed` variable is incremented by `t`. At the end of main.cpp, the x, y coordinate positons of each Body is printed to the screen using the body.h member function where_am_i().
  - body.h is a custom class designed to emulate the stars that are being simulated. It contains the gravitational constant, the object's postion in a cartisian coordinate field via x,y coordinates, the velocity of the object in the x and y axis and the net_force acting upon the object in the x and y axis. 
  -body.cpp
 
## Design Issues
  - main.cu does not work due to the dynamic creation of Body objects in main(). This design does not work with CUDA kernals due to memory issues. 
  - fail_body.cpp does not properly calculate the velocity or the acceleration of a Body. In addition to this, it has an overly complicated scheme to return the information calculated in order to update the attributes of the object.
## Tools
  - Visual Studio Code: run from command line using command g++ main.cpp -o nbody.exe body.cpp

## Libraries
  - random; used for creating random coordinates for the creation of Body objects
  - iostream; used for printing out Bodies' position within the coordinate grid
  - cmath; used for getting aboslute values, used in calculations of net force in body.cpp
  - math.h; used for calculating exponents, used in calculations of net force in body.cpp


## External References

  - http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
  - http://zonalandeducation.com/mstm/physics/mechanics/forces/newton/mightyFEqMA/mightyFEqMA.html
  - http://www.cs.hut.fi/~ctl/NBody.pdf
    - Sections one and two within this paper were used to 

# Front End/ Graphics
## Design Overview
  
## Design Issues
 
## Tools
 
## Libraries

## External References
