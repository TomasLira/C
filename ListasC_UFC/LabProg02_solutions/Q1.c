#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int *a =  malloc(sizeof(int));
int *b =  malloc(sizeof(int));
int r;

scanf("%d", &(*a));
scanf("%d", &(*b));

while(1){

r = (*a)%(*b);
if(r == 1 || r == 0){
printf("%d", *b);
break;
}

*a = *b;
*b = r;
}


free(a);
free(b);
return 0;
}