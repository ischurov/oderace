#include <iostream>
#include <fstream>
#include <stdio.h>
#include <boost/numeric/ublas/vector.hpp>
#include <math.h>

#include <sys/time.h>
#include <sys/resource.h>

//from http://stackoverflow.com/questions/2349776/how-can-i-benchmark-a-c-program-easily
double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}
using namespace boost::numeric::ublas;
/// @function rk_solve
/// @param t0 initial time
/// @param t1 new time
/// @param v right hand side, v=v(x,t,param)
/// @param param - parameters, which are passed to v
/// @param prec - precision
 
vector<double> rk_solve(double t0, double t1, vector<double> x0, vector<double> v (vector<double>, double, void*), void* param, int steps)
{
	double t;
	int i;
	vector<double> k1,k2, k3, k4;
	double h=(t1-t0)/steps;
	double halfh=0.5*h;
	vector<double> x(x0);
	t=t0;
	for(i=0;i<steps;i++)
	{
		k1=v(x,t,param);
		k2=v(x+halfh*k1,t+halfh,param);
		k3=v(x+halfh*k2,t+halfh,param);
		k4=v(x+h*k3,t+h,param);
		x+=h*(k1+k2+k2+k3+k3+k4)/6.;
		t+=h;
	}
	return x;
}

vector <double> Xdot(vector <double> X, double t, void* param)
{
    vector <double> ret(2);
    double* eps_p=(double*) param;
    double cosx=cos(X(0));
    double cosy=cos(X(1));
    ret(0)=cosx+1.4+cosy;
    ret(1)=*eps_p;
    return ret;
}
//show the trajectory (to doublecheck that solver works ok)
#define SHOWTRAJ
main()
{
    double eps=0.1;
    double prec=1.4E-8;
    vector<double> X(2);
    int rk_steps=10;
    int rk_steps_step=10;
    double timer;
    double oldx;
    bool first=true;
    int iterates=1000;
    int i;
    int trajpoints=700;
    int trajstep;
    for(;;)
    {
	X(0)=0;
	X(1)=0;
	X=rk_solve(0,2*M_PI/eps,X,Xdot,&eps,rk_steps);
	if(first)
	{
	    first=false;
	    oldx=X(0);
	}
	else
	{
	    if(fabs(oldx-X(0))/(fabs(X(0)+1))<prec)
	    {
		break;
	    }
	    else
	    {
		oldx=X(0);
	    }
	}
	rk_steps+=rk_steps_step;
    }
    timer=get_time();
    for(i=0;i<iterates;i++)
    {
	X(0)=0;
	X(1)=0;
	X=rk_solve(0,2*M_PI/eps,X,Xdot,&eps,rk_steps);
    }
    timer=get_time()-timer;

#ifdef SHOWTRAJ
    trajstep=int(double(rk_steps)/trajpoints);
    X(0)=0;
    X(1)=0;
    for(i=0;i<trajpoints;i++)
    {
	X=rk_solve(0,2*M_PI/eps/trajpoints,X,Xdot,&eps,trajstep);
	std::cout << X(1) << " " << X(0) << std::endl;
    }
#endif
    std::cout << "#The time is " << timer << std::endl << "#For x0 = 0, eps = " << eps << " and precision is " << prec << ", X(2pi) = " << X(0) << " with " << rk_steps << " steps and " << iterates << " iterations" << std::endl;
    return 0;
} 
