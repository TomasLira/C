#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct ponto{
float x;
float y;
}Ponto;

typedef struct triangulo{

Ponto p1;
Ponto p2;
Ponto p3;
}Triangulo;
// to see if the point isint  the triangle , it's necessary to create a algorithm that calculates the three areas that the point in the coordinates produce and see if it's = to area of the triangle

Triangulo *tria_cria(Ponto *p1 , Ponto *p2 , Ponto *p3){

Triangulo *t = (Triangulo *)malloc(sizeof(Triangulo));
t->p1.x = p1->x;
t->p1.y = p1->y;
t->p2.x = p2->x;
t->p2.y = p2->y;
t->p3.x = p3->x;
t->p3.y = p3->y;
}

Triangulo *tria_libera(Triangulo *t){
free(t);
}

void tria_atribui(Triangulo *t, Ponto *p1 , Ponto *p2, Ponto *p3){
t->p1.x = p1->x;
t->p1.y = p1->y;
t->p2.x = p2->x;
t->p2.y = p2->y;
t->p3.x = p3->x;
t->p3.y = p3->y;
}

int tria_verifica(Triangulo *t , Ponto *p){

float lado_1 = sqrt(pow(t->p1.x - t->p2.x,2) + pow(t->p1.y - t->p2.y,2));
float lado_2 = sqrt(pow(t->p1.x - t->p3.x,2) + pow(t->p1.y - t->p3.y,2));
float lado_3 = sqrt(pow(t->p2.x - t->p3.x,2) + pow(t->p2.y - t->p3.y,2));
printf("we have %f %f %f \n", lado_1 , lado_2 , lado_3);
if( (lado_1 > lado_2 + lado_3) || (lado_3 > lado_2 + lado_1) || (lado_2 > lado_1 + lado_3) ) return 0;
return 1;
}

float tria_area(Triangulo *t){

float lado_1 = sqrt(pow(t->p1.x - t->p2.x,2) + pow(t->p1.y - t->p2.y,2));
float lado_2 = sqrt(pow(t->p1.x - t->p3.x,2) + pow(t->p1.y - t->p3.y,2));
float lado_3 = sqrt(pow(t->p2.x - t->p3.x,2) + pow(t->p2.y - t->p3.y,2));            

float p = (lado_1+lado_2+lado_3)/2;
return sqrt(p*(p-lado_1)*(p- lado_2)*(p-lado_3));
}


int main(){

Ponto p,p1,p2,p3;

scanf("%f%f",&p1.x, &p1.y);
scanf("%f%f",&p2.x, &p2.y);
scanf("%f%f",&p3.x, &p3.y);
printf("we have %f %f %f %f %f %f\n", p1.x, p1.y,p2.x, p2.y,p3.x, p3.y);
Triangulo *t  = tria_cria(&p1,&p2,&p3);

printf("we have %f %f %f %f %f %f\n", t->p1.x, t->p1.y,t->p2.x, t->p2.y,t->p3.x, t->p3.y);
printf("Print new values for pointers!\n");

scanf("%f%f",&p1.x, &p1.y);
scanf("%f%f",&p2.x, &p2.y);
scanf("%f%f",&p3.x, &p3.y);

tria_atribui(t,&p1,&p2,&p3);
printf("we have %f %f %f %f %f %f\n", t->p1.x, t->p1.y,t->p2.x, t->p2.y,t->p3.x, t->p3.y);

printf("%d\n",tria_verifica(t,&p));

float tmp = tria_area(t);
printf("%f",tmp);

tria_libera(t);
return 0;
}