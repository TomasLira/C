#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(float arr[], int n){

if(n == 1) return arr[0];

return arr[0]+ sum(&arr[1],n-1);
}

void fill_array(float *arr , int size){

if(size < 1) return;
scanf("%f",&arr[0]);
return fill_array(&arr[1],size-1);
}

int main(){
int n;
printf("Digite o tamanho");
scanf("%d",&n);
float arr[n];
fill_array(arr,n);
sum(arr,n);
printf("A media eh: %f ",sum(arr,n)/n);
    

return 0;
}