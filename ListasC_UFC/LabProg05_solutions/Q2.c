#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct ponto{
float x;
float y;
}Ponto;

typedef struct circulo{

Ponto p;
float r;
}Circulo;

Circulo* circ_cria();
void circ_libera(Circulo* c);
void circ_atribui(Circulo* c, float x, float y, float r);
int circ_pertence(Circulo* c, Ponto* p);
float circ_area(Circulo* c);


Circulo *circ_cria(){
Circulo *circ = (Circulo *)malloc(sizeof(Circulo));
scanf("%f%f%f", &circ->p.x , &circ->p.y , &circ->r);
return circ;
}

void circ_libera(Circulo* c){
    free(c);
}

void circ_atribui(Circulo* c, float x, float y, float r){
c->p.x = x;
c->p.y = y;
c->r = r;
}

int circ_pertence(Circulo* c, Ponto* p){

float dis = sqrt(pow(c->p.x - p->x,2) + pow(c->p.y - p->y,2));

if(dis > c->r) return 0;
else return 1;
}

float circ_area(Circulo* c){

return M_PI*c->r*c->r;
}


int main(){
Ponto *point;
printf("Choose the coordinates x,y and radius for circ1!\n");
Circulo *circ1 = circ_cria();
printf("%f, %f and %f\n", circ1->p.x , circ1->p.y , circ1->r);
float x, y , r;
printf("Choose new coordinates x,y and radius for circ1!\n");
scanf("%f%f%f", &x , &y, &r);
circ_atribui(circ1,x,y,r);
printf("%f, %f and %f", circ1->p.x , circ1->p.y , circ1->r);
printf("\nChoose  coordinates x,y for our point!\n");
scanf("%f%f", &point->x , &point->y);

circ_pertence(circ1,point) ? printf("Pertence ao circulo!\n") :  printf("Nao Pertence ao circulo!\n");
printf("The area of our circle is: %f",circ_area(circ1));

circ_libera(circ1);
return 0;
}