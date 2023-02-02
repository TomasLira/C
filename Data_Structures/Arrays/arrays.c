#include <stdlib.h>
#include <stdio.h>
#define INICIAL_CAPACITY 5

struct array
{
    int max_size; // In this code, max size will always be the current size of the array!
    int *vector;
};
typedef struct array Array;

Array *create_array()
{
    Array *array = (Array *)malloc(sizeof(Array));
    array->vector = (int *)malloc(sizeof(int *) * INICIAL_CAPACITY);
    array->max_size = INICIAL_CAPACITY;

    return array;
}

void recursive_fill_array(int *vector, int current_size)
{

    if (vector == NULL || current_size < 0)
        exit(1);

    if (current_size < 1)
        return;

    int number_to_be_inserted;
    printf("Choose a number to be inserted in the array!\n");
    scanf("%d", &number_to_be_inserted);

    vector[0] = number_to_be_inserted;
    return recursive_fill_array(&vector[1], current_size - 1);
}

void fill_array(Array *array)
{
    if (array == NULL)
        exit(1);
    recursive_fill_array(array->vector, array->max_size);

    int tmp_elements = 1;
    while (tmp_elements != 0)
    {
        printf("Limit reached! How many more elements do you wish to add?\n");

        scanf("%d", &tmp_elements);
        int aux_size = array->max_size;
        array->max_size += tmp_elements;

        array->vector = (int *)realloc(array->vector, array->max_size * sizeof(int *));
        recursive_fill_array(&(array->vector)[array->max_size - tmp_elements], array->max_size - aux_size);
    }
}

void reverse_elements_in_array(Array *array)
{
    if (array == NULL)
        exit(1);

    int idxL = 0, idxR = array->max_size - 1, tmp;

    while (idxL < idxR)
    {

        tmp = array->vector[idxR];
        array->vector[idxR] = array->vector[idxL];
        array->vector[idxL] = tmp;
        idxL++;
        idxR--;
    }
}

void recursive_quick_sort(int *vector, int vector_start, int vector_end)
{

    if (vector == NULL)
        exit(1);

    if (vector_start > vector_end)
        return;

    int pivot = vector_start;
    int idxL = vector_start, idxR = vector_end;

    while (idxL < idxR)
    {

        while (vector[idxL] < vector[pivot] && idxL < vector_end)
            idxL++;
        while (vector[idxR] > vector[pivot] && idxR > vector_start)
            idxR--;

        if (idxL < idxR)
        {
            int tmp = vector[idxL];
            vector[idxL] = vector[idxR];
            vector[idxR] = tmp;
        }
    }

    int tmp = vector[pivot];
    vector[pivot] = vector[idxR];
    vector[idxR] = tmp;

    recursive_quick_sort(vector, vector_start, idxR - 1);
    recursive_quick_sort(vector, idxR + 1, vector_end);
}

void quick_sort(Array *array)
{
    if (array == NULL)
        exit(1);
    recursive_quick_sort(array->vector, 0, array->max_size - 1);
}

void show_elements_in_array(Array *array)
{
    for (short i = 0; i < array->max_size; i++)
        printf("%d\t", array->vector[i]);
    printf("\n");
}

void free_array(Array **array){
if(array == NULL) return;
if( (*array)->max_size > 0 ){
    free((*array)->vector);
    (*array)->vector = NULL;
}
free(*array);
*array = NULL;
}

int main()
{
    Array *arr = create_array();
    fill_array(arr);
    show_elements_in_array(arr);
    reverse_elements_in_array(arr);
    show_elements_in_array(arr);
    quick_sort(arr);
    show_elements_in_array(arr);
    free_array(&arr);
    return 0;
}