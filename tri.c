#include <stdio.h>
#include <math.h>

#define pi 3.1416

int main()
{
	
	int x;
	double d=(pi/180);
	
	printf("\"x\",\"f\",\"g\",\"h\"\n");
	for(int i=0; i<=360; i++)
	{
		printf("%4d,%.5f,%.5f,%.5f\n",i,sin(d*i),cos(d*i),(sin(d*i)-cos(d*i)));
	}

	return 0;
}
