--Notes--

This should represent a vector of floats graphically, but it may need tweaking. 
I tried to add as many comments as possible to show what is going on

It has not been tested with very large number sets, so the memory may need to be allocated dynamically
before that will work smoothly.

The driver.cpp is just an example to show how it works, but the .h should do all the graphics work if you give it some float vectors.

--OpenGL and Freeglut Instructions--

I used freeglut to simplify the process some, so you need to include the librarys as targets for the project.
I'll add the version and libraries for WIN10 here in the hopes that they will work for you too.

To include these in VS2017: 

1.Go to the solution in the VS window, right click it, and select "properties".
2.Go to the C/C++ part and right click that dropdown.
3.Click the "Additional Include Directories" and select edit.
4.Add a new folder to watch at the top then edit it and point to the location of the "include" folder I included in the freeglut folder of the zip.
5.In the properties window, go to the Linker dropdown and select Input.
6.Click the "Additional Dependencies" and edit it.
7.At the top, manually type "freeglut.lib".
8.Go back the the Linker dropdown and select General this time.
9.Pick the "Additional Library Directories" section and add a directory just like in step 4, linking to the "lib" folder this time.

The freeglut and openGL should compile now, if not you may need to go into the bin folder included with this readme and add the freeglut.dll in it (not the x64 one) to
the folder with your VS project.


