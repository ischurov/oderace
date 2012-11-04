#include <math.h>

main()
{
    long int i;
    for(i=0;i<1E8;i++)
    {
	cos(i+0.1);
    }
    return 0;
}
