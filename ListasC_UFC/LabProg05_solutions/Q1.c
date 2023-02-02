#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct ponto{

float x;
float y;
}Ponto;

Ponto* pto_cria(float x, float y);
void pto_libera(Ponto* p);
void pto_atribui(Ponto* p, float x, float y);
float pto_distancia(Ponto* p1, Ponto* p2);


Ponto *pto_cria(float x , float y){

Ponto *p = (Ponto *)malloc(sizeof(Ponto));
scanf("%f%f", &p->x , &p->y);
return p;
}

void pto_libera(Ponto *point){

    free(point);
}

void pto_atribui(Ponto* point, float x, float y){
scanf("%f%f", &x, &y);
point->x = x;
point->y = y;
printf("we have %f and %f\n", point->x,point->y );
}

float pto_distancia(Ponto* p1, Ponto* p2){

return sqrt( pow(p1->x - p2->x,2) + pow(p1->y - p2->y,2));
}


int main(){
float x,y;
printf("type the coordinates of point1!\n");
Ponto *point1 = pto_cria(x,y);
printf("we have %f and %f\n",point1->x,point1->y );
printf("type the new coordinates x,y of point1!\n");
pto_atribui(point1,x,y);
printf("type the coordinates of x,y of point2!\n");
Ponto *point2  = pto_cria(x,y);
printf("The distance of these two points is: %f\n",pto_distancia(point1, point2) );

pto_libera(point1);
pto_libera(point2);
return 0;
}