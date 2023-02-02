#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void fill_array(int *arr , int size){

if(size < 1) return;
scanf("%d",&arr[0]);
return fill_array(&arr[1],size-1);
}


int find_maxElement(int arr[],int size,int msub){

if(size == 1) return arr[0] > msub ? arr[0] : msub;
if(arr[0] > msub) msub = arr[0];
return find_maxElement(&arr[1] , size -1,msub);
}

int find_minElement(int arr[],int size, int msub){

for(short i =0 ; i < size ; i++){
    if(arr[i] < msub) msub = arr[i];
}
return msub;
}

int main(){
int size =10;
int *arr = (int*)malloc(sizeof(int)*size);
fill_array(arr,size);
printf("\n");
printf("%d\n",find_maxElement(arr,size,INT_MIN));
printf("%d\n",find_minElement(arr,size,INT_MAX));

free(arr);
return 0;
}