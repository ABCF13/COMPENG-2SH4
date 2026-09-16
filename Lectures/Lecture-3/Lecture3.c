#include <stdio.h>

double my_mean_square(double x, double y);

int main(void)
{


    double a=10.0;
    double b=20.0;
    double c=my_mean_square(a, b);
    printf("%f",&c);
    return 0;
};

double my_mean_square(double x, double y){
    double z;
    x=x*x;
    y=y*y;
    z=(x+y)/2.0;

    return z;
};
