#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 5

struct node
{
    int value;
    struct node *next;
};
typedef struct node Node;

struct stack
{
    int max_size;
    Node *first;
};
typedef struct stack Stack;

Stack *create_stack()
{
    Stack *tmp = (Stack *)malloc(sizeof(Stack));
    tmp->max_size = MAXSIZE;
    return tmp;
}

void create_node(Stack *stack, int current_size)
{
    if (current_size == stack->max_size) return;
    int value;

    if (current_size == 0)
    {

        Node *new_node = (Node *)malloc(sizeof(Node));

        stack->first = new_node;
        new_node->next = NULL;
        printf("Choose a value! to insert into your stack!\n");
        scanf("%d", &value);
        new_node->value = value;
    }
    else
    {
        for (Node *aux = stack->first; aux != NULL; aux = aux->next)
        {
            if (aux->next == NULL)
            {
                Node *new_node = (Node *)malloc(sizeof(Node));
                aux->next = new_node;
                new_node->next = NULL;
                scanf("%d", &value);
                new_node->value = value;
                break;
            }
        }
    }
    return create_node(stack, current_size+1);
}

void fill_stack(Stack *stack)
{
    if (stack == NULL) exit(1);
    create_node(stack, 0);
}

void show_elements_in_stack(Stack *stack)
{
    for (Node *aux = stack->first; aux != NULL; aux = aux->next)
    {
        printf("%d\t", aux->value);
    }
}

int main()
{

    Stack *stack = create_stack();
    fill_stack(stack);
    show_elements_in_stack(stack);
    return 0;
}