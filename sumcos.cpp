#include <math.h>
#include <iostream>

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

main()
{
    int iterations=10000;
    int experiments=10000;
    int i,j;
    double x;
    double sum;
    double step=M_PI*sqrt(2);
    double timer=get_time();
    for(i=0;i<experiments;i++)
    {
	sum=0;
	x=0;
	for(j=0;j<experiments;j++)
	{
	    x+=step;
	    sum+=cos(x);
	}
    }
    std::cout << "Total time : " << get_time()-timer;
}

