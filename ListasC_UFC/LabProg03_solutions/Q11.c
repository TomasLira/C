#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void fill_matrix(int *mat , int n , int m){

for(short i =0 ; i < n ; i++){
    for(short j =0 ; j < m ; j++){
        scanf("%d", &mat[i*n +j]);
    }   
}

}

void print_matrix(int *mat , int n , int m){

for(short i =0 ; i < n ; i++){
    for(short j =0 ; j < m ; j++){
        printf("%d\t", mat[i*n +j]);
    }
    printf("\n");   
}

}

void multi_por_escalar(int **mat,int n,int m,int num){

for(short i =0 ; i < n ; i++){
    for(short j =0 ; j < m ; j++){
        mat[i][j] = num* mat[i][j];
    }  
}
}

int main(){

int n , m;
scanf("%d%d",&n,&m);

int **mat = (int **)malloc(sizeof(int)*n);
for(short i = 0 ; i < m ;i++) mat[i] = (int *)malloc(m*sizeof(int));



fill_matrix(&mat[0][0],n,m);

/*
if(mat == NULL)exit(1);

for(short i =0 ; i < n ; i++){
    for(short j =0 ; j < m ; j++){
        scanf("%d", &mat[i][j]);
    }   
}
*/


print_matrix(&mat[0][0],n,m);

/*
for(short i =0 ; i < n ; i++){
    for(short j =0 ; j < m ; j++){
        printf("%d\t", mat[i][j]);
    }   
    printf("\n");
}
*/
int num;
printf("Digite numero\n");
scanf("%d", &num);

multi_por_escalar(mat,n,m,num);
print_matrix(&mat[0][0],n,m);


return 0;
}