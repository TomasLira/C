#include <stdlib.h>
#include <stdio.h>
#define INICIAL_SIZE 5

struct node
{
    int value;
    struct node *next;
};
typedef struct node Node;

// Stack is just a abstract name, this struct has the purpuse of organizing our linked list!
struct stack
{
    int max_size;
    Node *first;
};
typedef struct stack Stack;

Stack *create_stack()
{

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->first = NULL;
    stack->max_size = INICIAL_SIZE;
    return stack;
}

Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

void insert_element_in_stack(Stack *stack, int current_size)
{
    if (stack == NULL)
        exit(1);

    int number_to_be_inserted;
    if (current_size == stack->max_size)
    {
        printf("Inicial capacity reached, you you wish to insert how many more nodes?");
        scanf("%d", &number_to_be_inserted);
        if (number_to_be_inserted == 0)
            return;
        else
            stack->max_size = stack->max_size + number_to_be_inserted;
    }

    if (stack->first == NULL)
    {

        Node *node = create_node();
        stack->first = node;

        printf("Choose a number to be inserted in our linked list!\n");
        scanf("%d", &number_to_be_inserted);

        node->value = number_to_be_inserted;
        return insert_element_in_stack(stack, current_size + 1);
    }
    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {

        if (tmp->next == NULL)
        {

            Node *node = create_node();
            printf("Choose a number to be inserted in our linked list!\n");
            scanf("%d", &number_to_be_inserted);
            node->value = number_to_be_inserted;
            tmp->next = node;
            break;
        }
    }
    return insert_element_in_stack(stack, current_size + 1);
}

void delete_value_in_first_node(Stack *stack)
{

    if (stack == NULL)
        exit(1);

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->next != NULL)
            tmp->value = tmp->next->value;
    }

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->next->next == NULL)
        {
            free(&tmp->next);
            tmp->next = NULL;
            break;
        }
    }
}

void delete_value_in_last_node(Stack *stack)
{
    if (stack == NULL)
        exit(1);

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->next->next == NULL)
        {
            free(&tmp->next);
            tmp->next = NULL;
            break;
        }
    }
}

int is_in_linked_list(Stack *stack)
{

    if (stack == NULL)
        exit(1);

    int number_to_find;
    printf("Choose a number to see if it's in the linked list!\n");
    scanf("%d", &number_to_find);

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {

        if (tmp->value == number_to_find)
            return 1;
    }
    return 0;
}

void replace_numbers_in_linked_list(Stack *stack)
{

    if (stack == NULL)
        exit(1);

    int number_to_replace, number_to_choose;

    printf("Choose a number you want to replace\n");
    scanf("%d", &number_to_choose);

    printf("Choose the number to replace!\n");
    scanf("%d", &number_to_replace);

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {

        if (tmp->value == number_to_choose)
            tmp->value = number_to_replace;
    }
}

int length_of_stack(Stack *stack)
{

    if (stack == NULL)
        exit(1);

    int counter = 0;
    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        counter++;
    }
    return counter;
}

void reverse_linked_list(Stack *stack)
{

    if (stack == NULL)
        exit(1);

    int *arr_tmp = (int *)malloc(sizeof(int) * length_of_stack(stack));
    int idx = 0;
    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        arr_tmp[idx] = tmp->value;
        idx++;
    }
    idx = 0;

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        tmp->value = arr_tmp[length_of_stack(stack) - 1 - idx];
        idx++;
    }
    free(arr_tmp);
    arr_tmp = NULL;
}

void merge(int *arr, int *left_arr, int *right_arr, int left_size, int right_size)
{

    if (arr == NULL || left_arr == NULL || right_arr == NULL || left_size == 0 || right_size == 0)
        exit(1);

    int left_idx = 0, right_idx = 0, idx = 0;

    while (idx < left_size + right_size)
    {

        if (left_arr[left_idx] < right_arr[right_idx])
        {

            if (left_idx >= left_size && right_idx < right_size)
            {
                arr[idx] = right_arr[right_idx];
                idx++;
                right_idx++;
                continue;
            }

            arr[idx] = left_arr[left_idx];
            idx++;
            left_idx++;
        }
        else
        {
            if (left_idx < left_size && right_idx >= right_size)
            {
                arr[idx] = left_arr[left_idx];
                idx++;
                left_idx++;
                continue;
            }

            arr[idx] = right_arr[right_idx];
            idx++;
            right_idx++;
        }
    }
}

void merge_sort(int *arr, int size)
{

    if (arr == NULL || size == 0)
        exit(1);

    if (size < 2)
        return;

    int mid = size / 2;

    int *left_arr = (int *)malloc(sizeof(int) * mid);
    int *right_arr = (int *)malloc(sizeof(int) * (size - mid));

    for (int i = 0; i < mid; i++)
        left_arr[i] = arr[i];
    for (int i = mid; i < size; i++)
        right_arr[i - mid] = arr[i];

    merge_sort(left_arr, mid);
    merge_sort(right_arr, size - mid);

    merge(arr, left_arr, right_arr, mid, size - mid);

    free(right_arr);
    free(left_arr);
}

void sort_linked_list(Stack *stack)
{

    if (stack == NULL)
        exit(1);

    int *arr_tmp = (int *)malloc(sizeof(int) * length_of_stack(stack));
    int idx = 0;
    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        arr_tmp[idx] = tmp->value;
        idx++;
    }

    idx = 0;

    merge_sort(arr_tmp, length_of_stack(stack));

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        tmp->value = arr_tmp[idx];
        idx++;
    }
    free(arr_tmp);
}

void show_elements_in_stack(Stack *stack)
{
    if (stack == NULL)
        exit(1);

    for (Node *tmp = stack->first; tmp != NULL; tmp = tmp->next)
    {
        printf("%d\t", tmp->value);
    }
    printf("\n");
}


int main()
{
    Stack *stack = create_stack();
    insert_element_in_stack(stack,0);
    show_elements_in_stack(stack);
    delete_value_in_first_node(stack);
    show_elements_in_stack(stack);
    delete_value_in_last_node(stack);
    show_elements_in_stack(stack);
    replace_numbers_in_linked_list(stack);
    show_elements_in_stack(stack);
    reverse_linked_list(stack);
    show_elements_in_stack(stack);
    sort_linked_list(stack);
    show_elements_in_stack(stack);
    free_linked_list(&stack);
    return 0;
}