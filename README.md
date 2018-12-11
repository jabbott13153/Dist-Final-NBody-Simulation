# Dist-Final-NBody-Simulation
An NBody gravitational simulation utilizing c++

## Design Overview
  The project consists of three seperate pieces. Main.cpp takes care of all of the actual allocating of memory and executing of methods. body.h is a custom class designed to emulate the stars that are being simulated. It contains the gravitational constant, the object's postion in a cartisian coordinate field via x,y coordinates, the velocity of the object in the x and y axis and the net_force acting upon the object in the x and y axis. 
 
## Design Issues
  main.cu does not work due to the dynamic creation of Body objects in main(). This design does not work with CUDA kernals due to memory issues. 
## Tools
  -Visual Studio Code: run from command line using command g++ main.cpp -o nbody.exe body.cpp

## Libraries
  -random; used for creating random coordinates for the creation of Body objects
  -iostream; used for printing out Bodies' position within the coordinate grid
  -cmath; used for getting aboslute values, used in calculations of 


## External References

  -http://www.cs.ucy.ac.cy/~ppapap01/nbody/Presentation.pdf
  -http://zonalandeducation.com/mstm/physics/mechanics/forces/newton/mightyFEqMA/mightyFEqMA.html

