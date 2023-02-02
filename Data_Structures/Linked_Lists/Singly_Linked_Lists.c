#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 5


struct node{
int value;
struct node *next;
};
typedef struct node Node;

struct stack{
int max_size;
Node *first;
};
typedef struct stack Stack;

// Cretting a linked list without recursion!-----------------

void create_first_node(Stack *stack, int value){

Node *node = (Node *)malloc(sizeof(Node));
node->value = value;
stack->first = node;
node->next = NULL;
}

void create_node(Stack *stack,int value){

for(Node *tmp = stack->first ; tmp != NULL ; tmp = tmp->next){
    if(tmp->next == NULL){
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = value;
        tmp->next = node;
        node->next = NULL;
        break;
    }
}
}


Stack  *create_stack(){
Stack *stack = (Stack *)malloc(sizeof(stack));
stack->max_size = MAXSIZE;
return stack;
}

void fill_stack(Stack *stack){
int number_to_fill;


for(short i = 0 ; i < stack->max_size ; i++){
scanf("%d",&number_to_fill);
if( i == 0) create_first_node(stack,number_to_fill);
else{
create_node(stack,number_to_fill);
}
}
}

void show_elements_in_stack(Stack *stack){

for(Node *tmp = stack->first ; tmp != NULL ; tmp = tmp->next){
    printf("%d\n",tmp->value);
}
}

int main(){

Stack *stack = create_stack();
fill_stack(stack);
show_elements_in_stack(stack);

return 0;
}


