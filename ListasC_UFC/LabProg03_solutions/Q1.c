#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void common_elements(int *a , int *b ,int size_1 ,int size_2){

for(short i =0 ; i< size_1 ; i++){
    for(short j = 0 ; j < size_2 ; j++){
        if(a[i]  == b[j]) printf("%d\t", a[i]); 
    }
}            
}

int main(){

int *a = (int *)malloc(sizeof(int)*5);
int *b = (int *)malloc(sizeof(int)*8);

for(int i =0 ; i < 5 ; i++ ) scanf("%d",a+ i);
for(int i =0 ; i < 5 ; i++ ) printf("%d\t",*(a+ i));

printf("\n");

for(int i =0 ; i < 8 ; i++ ) scanf("%d", b+ i);
for(int i =0 ; i < 8 ; i++ ) printf("%d\t",*(b+ i));

printf("\n");

common_elements(a,b,5,8);

return 0;
}