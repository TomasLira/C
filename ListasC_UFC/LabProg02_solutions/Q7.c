#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double recursive_power(double x , int k){

if(k < 1) return 1;
return x*recursive_power(x,k-1);
}


int main(){

double x;
int k;

scanf("%lf%d",&x,&k);

printf("%lf\t",recursive_power(x,k));
return 0;
}