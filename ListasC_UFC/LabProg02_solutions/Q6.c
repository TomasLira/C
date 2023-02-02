#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double delta(double a , double b , double c){
return pow(b,2) - 4*a*c;
}

double raizes(double a, double b , double c, double *px1 , double *px2){

*px1 =(b + delta(a,b,c))/2.0;
*px2 =(b - delta(a,b,c))/2.0;
}

int main(){
double a,b,c;
scanf("%lf%lf%lf",&a,&b,&c);
double px1 , px2;
raizes(a,b,c,&px1,&px2);
printf("%lf %lf",px1 ,px2);
return 0;
}