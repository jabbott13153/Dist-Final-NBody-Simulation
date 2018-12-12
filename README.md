# Dist-Final-NBody-Simulation
An NBody gravitational simulation utilizing c++

# Calculations and Backend
## Design Overview
This program simulates the physics of N stars upon eachother, with the only force being that which is exerted upon the stars by eachother.  
  - Main.cpp takes care of all of the actual allocating of memory and executing of methods. First, `#define N` defines how many stars(Bodies) the program will be simulating the physics of. It then creates a random number generator that creates a float between (1, 1000). Next, the program dynamically creates N pointer objects of the custom class Body, with each object having their positions being initialized using the random engine. `const float t` defines the timestep that the program will be using, and `time_passed`, a float that keeps track of how many timesteps have passed (in the form of a cumulative sum) during the execution of the program. A nested loop is defined with the variables `i`, `j`, and `k`. `i` keeps track of how many timesteps total the program will go through before terminating, and `j` and `k` make sure that no Body does any calculations on itself. This would lead to an incorrect result at the end of the program. Inside of all three nested loops, each body calculates its position, velocity, and net force relative to every other body the program is simulating. Inside of the `i` loop only, the `time_passed` variable is incremented by `t`. At the end of main.cpp, the x, y coordinate positons of each Body is printed to the screen using the body.h member function where_am_i().
  - body.h is a custom class designed to emulate the stars that are being simulated. There are two private attributes, and four public attributes. The private attributes are `m`, which is the mass of the Body, and `g`, which is the gravitational constant. The public attributes are `position_x`, which is the Body's position in the form of the x coordinate position, `position_y`, which is the Body's position in the form of the y coordinate position , `velocity[2]` , in which [0] = x plane velocity, and [1] = y plane velocity, and `net_force[2]`, in which [0] = x plane net force, [1] = y plane net force. Two get functions are defined to get the `m` and `g` private variables. `newton_law_universal_gravitation` calculates the force between two Bodies, but is defined in body.cpp. `update_pos` updates `position_x` and `position_y`, but is defined in body.cpp. `update_vel` updates the x and y velocities of the body, but is defined in body.cpp. The constructor takes two arguments (`p_x` and `p_y`) which defines the x, y coordinate starting positons, and sets `velocity[0]` and `velocity[1]` to 0.00. `update` executes `newton_law_universal_gravitation`, `update_pos`, and `update_vel` in sequence to streamline and simplify the implementation in main.cpp. `where_am_i` retrieves and prints out the Body's x and y coordinates.
  - body.cpp implements `newton_law_universal_gravitation`, `update_pos`,  `update_vel`, and `update` from body.h.
 
## Design Issues
  - main.cu does not work due to the dynamic creation of Body objects in main(). This design does not work with CUDA kernals due to memory issues. 
  - fail_body.cpp does not properly calculate the velocity or the acceleration of a Body. In addition to this, it has an overly complicated scheme to return the information calculated in order to update the attributes of the object.
  - leapfrog.cu is an example of a leapfrog integration scheme that has been coded in c, but is not used in this program.
  
## Tools
  - Visual Studio Code: run from command line using command g++ main.cpp -o nbody.exe body.cpp

## Libraries
  - random; used for creating random coordinates for the creation of Body objects
  - iostream; used for printing out Bodies' position within the coordinate grid
  - cmath; used for getting aboslute values, used in calculations of net force in body.cpp
  - math.h; used for calculating exponents, used in calculations of net force in body.cpp


## External References

  - http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
    - Slides number 10-11 were used to define the attributes of body.h and the formula for `newton_law_universal_gravitation`. In addition to this, it was also used by the developer to better understand the problem and solution posed by N-body simulations.
  - http://zonalandeducation.com/mstm/physics/mechanics/forces/newton/mightyFEqMA/mightyFEqMA.html
    - This website was used to retrieve the formulas for `update_pos` and `update_vel` so that the developer could implement them.
  - http://www.cs.hut.fi/~ctl/NBody.pdf
    - Sections one and two within this paper were used to create fail_body.cpp, the developer's first attempt to implement methods that would correctly simulate the physics required by this program. In addition to this, the developer used this paper as their first resource in attempting to understand the problem at hand, as well as other possible implementation methods. This paper was also used as a resource in understanind the math that the simulation required.
  - Various Instructors, including Professor Griffith, Professor Rempe, Professor Kamesh, and Professor Jones.
  - Other students including Mr. Battista and Ms. La Fleur for troubleshooting mathematics involved.
  - Google: the developer referred to this resource often when troubleshooting and attempting to find formulas to recreate the physics needed by the program.

# Front End/ Graphics
## Design Overview
  
## Design Issues
 
## Tools
 
## Libraries

## External References
