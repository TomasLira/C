#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void misterio(int *a ,int *b){
int tmp = *a;
*a = *b;
*b = tmp;   
}

int main(){
int a = 6 , b = 10;
printf("a is %d and b is %d\n", a , b);
misterio( &a , &b);
printf("a is %d and b is %d", a , b);
return 0;
}