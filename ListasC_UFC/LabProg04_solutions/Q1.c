#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int fill_array(int *v , int size){

if(size < 1 ) return 0;

scanf("%d", &v[0]);
return fill_array(&v[1] , size -1);
}

int print_array(int *v , int size){

if(size < 1) return 0;
printf("%d\t", v[0]);
return print_array( &v[1] ,size -1);
}

void insert_elements_in_existing_array(int *v , int *size ,int addSize){
*(size) +=  addSize;
realloc(v,sizeof(int)*(*size));

for(int i = *(size) - addSize ; i < *(size) ; i++){
    scanf("%d",&v[i]);
}
}

int main(){
int size, addSize , op;
printf("Choose the inicial size of the array!\n");
scanf("%d",&size);
int *v = (int *)malloc(sizeof(int)*size);
if(v == NULL) exit(1);

fill_array(v,size);
print_array(v,size);

while(1){
printf("\nDo you wish to insert more elements in the array? (1 for yes and 0 for no)\n");
scanf("%d",&op);
if(op){
printf("How many  more elements do you want to insert in the array?\n");
scanf("%d", &addSize);

insert_elements_in_existing_array(v , &size , addSize);
}else break;
}
print_array(v,size);


free(v);
return 0;
}