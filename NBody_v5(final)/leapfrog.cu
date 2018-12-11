#include<math.h>
#include<stdio.h>

#define G 6.67408E-11 //the gravatational constant G

//adapted from: http://www.physics.drexel.edu/~steve/Courses/Comp_Phys/Integrators/leapfrog/
//date accessed: 12/4/2018

typedef double real;

#define N 2	/* Number of second-order equations */
#define GM 1	/* Constant in Coulomb's law */


/* Determine (vector) a = dv/dt, given (vector) x */

void deriv(int n, real x[], real dvdt[])
{
    real r2 = 0.0, r3i;
    int i;

    for (i = 0; i < n; i++) r2 += x[i]*x[i];
    r3i = GM / (r2*sqrt(r2));		/* Inverse-square force law */

    for (i = 0; i < n; i++) dvdt[i] = -x[i]*r3i;
}


/* Advance the velocity by dt2 using the Euler method */

void advance_vel(int n, real x[], real v[], real dt2)
{
    real dvdt[N];
    int i;

    deriv(n, x, dvdt);

    for (i = 0; i < n; i++) v[i] += dt2*dvdt[i];
}


static real e0;

/* Calculate the energy (inverse-square case ONLY!) */

real energy(int n, real x[], real v[])
{
    return 0.5 * (v[0]*v[0] + v[1]*v[1])
			- GM / sqrt(x[0]*x[0] + x[1]*x[1]);
}


void output(int n, real x[], real v[], real t, real dt)
{
    int i;
    real vv[N], dvdt[N];

    printf("%f", t);
    for (i = 0; i < n; i++)  printf(" %f", x[i]);

    /* Synchronize the velocity if necessary */

    for (i = 0; i < n; i++)  vv[i] = v[i];
    if (t > 0) {
	deriv(n, x, dvdt);
	for (i = 0; i < n; i++)  vv[i] -= 0.5*dt*dvdt[i];
    }

    printf(" %f", energy(n, x, vv) - e0);
    printf("\n");
}

void leapfrog(int n, real x[], real v[], real* t, real dt)
{
    real dvdt[N];
    int i;

    for (i = 0; i < n; i++) x[i] += dt*v[i];
    deriv(n, x, dvdt);
    for (i = 0; i < n; i++) v[i] += dt*dvdt[i];

    *t += dt;
}


main(int argc, char** argv)
{
    /* General integrator x(t). */

    /* Default integration parameters and initial conditions: */

    real t = 0, x[N] = {1.0, 0.0}, v[N] = {0.0, 0.75};
    real t_max = 100, dt = 0.01;

    int i;

    /* Parse the argument list. */

    for (i = 0; i < argc; i++)
	if (argv[i][0] == '-') {
	    switch (argv[i][1]) {

		case 'd':	dt = atof(argv[++i]); break;
		case 't':	t_max = atof(argv[++i]); break;
		case 'v':	v[1] = atof(argv[++i]); break;
	    }
	}

    e0 = energy(N, x, v);
    output(N, x, v, t, dt);
    advance_vel(N, x, v, 0.5*dt);

    while (t < t_max) {
	leapfrog(N, x, v, &t, dt);
	output(N, x, v, t, dt);
    }
}