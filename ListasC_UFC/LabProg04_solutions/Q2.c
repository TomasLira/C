#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ponto{

float x;
float y;
}Ponto;

typedef struct circulo{

Ponto p;
float r;
}Circulo;


void fill_circle_coordinates(Circulo *c1){
scanf("%f%f", &c1->p.x , &c1->p.y);
}

void print_circle_coordinates(Circulo *c1){
printf("%f and %f\n",c1->p.x , c1->p.y);
}

int distance(Circulo *c1, Circulo *c2){
return sqrt(pow(c1->p.x - c2->p.x,2) + pow(c1->p.y - c2->p.y,2));
}


int in_tan(Circulo *c1, Circulo *c2){
if( distance(c1,c2) == c1->r + c2->r) return 1;
else return 0;
}

int ex_tan(Circulo *c1, Circulo *c2){
if( distance(c1,c2) == c1->r * c2->r) return 1;
else return 0;
}

int ex(Circulo *c1, Circulo *c2){
if( distance(c1,c2) > c1->r + c2->r) return 1;
else return 0;
}

int sec(Circulo *c1, Circulo *c2){
if( distance(c1,c2) < c1->r + c2->r) return 1;
else return 0;
}

int in(Circulo *c1, Circulo *c2){
if( distance(c1,c2) < c1->r + c2->r) return 1;
else return 0;
}

int conc(Circulo *c1, Circulo *c2){
if( distance(c1,c2) == 0) return 1;
else return 0;
}



int check_distance(Circulo *c1,Circulo *c2){
if (conc(c1,c2)){
printf("Concêntricas!\n");
return 0;
}
if (in_tan(c1,c2)) printf("Tangentes Internas!\n");
if (ex_tan(c1,c2)) printf("Tangentes Internas!\n");
if (ex(c1,c2)) printf("Externas!\n");
if (sec(c1,c2)) printf("Secantes!\n");
if (in(c1,c2)) printf("Internas!\n");

}


int main(){
Circulo *c1 = (Circulo*)malloc(sizeof(Circulo));
Circulo *c2 = (Circulo*)malloc(sizeof(Circulo));

printf("Choose the coordinates of x,y for c1!\n");
//scanf("%f%f", &c1->p.x , &c1->p.y);
//printf("\n%f and %f\n",c1->p.x , c1->p.y); da o resultado correto em float!
fill_circle_coordinates(c1);
print_circle_coordinates(c1);

printf("Choose the radius of c1!\n");
scanf("%f", &c1->r);

printf("Choose the coordinates of x,y for c2!\n");
fill_circle_coordinates(c2);
print_circle_coordinates(c2);

printf("Choose the radius of c2!\n");
scanf("%f", &c2->r);

check_distance(c1,c2);

free(c1);
free(c2);
return 0;
}




