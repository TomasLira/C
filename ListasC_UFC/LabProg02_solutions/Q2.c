#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n){

if(n == 2) return 1;
else if( n < 2 || n%2 == 0) return 0;
else{

int lim = (int)sqrt(n);
for(int i = 3 ; i <= lim ; i+= 2){
    if(n%i == 0) return 0;
}
return 1;
}
}


int main(){

int x;
scanf("%d" , &x);

for(int i = 1; i < x ; i+= 3) if(is_prime(i)) printf("%d\t",i);
return 0;
}