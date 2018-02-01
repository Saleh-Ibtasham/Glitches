#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f ( double x ) {
   return (x*x + x - 1);
}

int main() {
   double a=-1, b=0, x0, eps=1.0e-6;
   int i=0;


   if (f(a)*f(b) >= 0) {
     printf ("Err.. in domain\n");
     exit(0);
   } 


AGAIN:
//   x0 = (a+b)/2.0;
   x0 = (b*f(a) - a*f(b))/(f(a) - f(b));
   i++;

   if (fabs(f(x0)) < eps ) {
     printf ("Root = %14.9g' Iter= %d\n", x0, i);
     //exit(0);
   } 


   if (f(a)*f(x0) > 0) 
     a = x0;
   else
     b = x0;
  

   goto AGAIN; 
}
