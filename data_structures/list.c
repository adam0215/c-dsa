#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define INIT_SIZE 10;
#define INIT_GROWTH_FACTOR 1.5;

typedef struct DynamicArray
{
    int init_size;
    float growth_factor;
    unsigned int size;
    unsigned int n_items;
    int *array;
} DynamicArray;

DynamicArray *new_dynamic_array()
{
    DynamicArray *dynamic_array = malloc(sizeof(DynamicArray));
    dynamic_array->init_size = INIT_SIZE;
    dynamic_array->growth_factor = INIT_GROWTH_FACTOR;
    dynamic_array->array = (int *)malloc(dynamic_array->init_size * sizeof(int));
    dynamic_array->size = dynamic_array->init_size;
    dynamic_array->n_items = 0;

    return dynamic_array;
}

void _da_grow(DynamicArray *array)
{
    // Expand according to set growth factor
    int new_size = ceil(array->size * array->growth_factor);
    int *new_array = (int *)malloc(new_size * sizeof(int));

    for (int i = 0; i <= array->n_items; i++)
    {
        new_array[i] = array->array[i];
    }

    array->size = new_size;
    free(array->array);
    array->array = new_array;

    printf("(debug) Expanded to size: %d\n", new_size);
}

void _da_shrink(DynamicArray *array)
{
    // Half the size
    int new_size = ceil(array->size / 2);
    int *new_array = (int *)malloc(new_size * sizeof(int));

    for (int i = 0; i <= array->n_items; i++)
    {
        new_array[i] = array->array[i];
    }

    array->size = new_size;
    free(array->array);
    array->array = new_array;

    printf("(debug) Shrunk to size: %d\n", new_size);
}

void _da_add(int index, int value, DynamicArray *array)
{
    array->array[index] = value;
    array->n_items++;
    return;
}

void _da_delete(int index, DynamicArray *array)
{
    array->array[index] = INT_MIN;

    // Shift elements to the left
    for (int i = index + 1; i < array->size; i++)
    {
        array->array[i - 1] = array->array[i];
    }

    array->n_items--;
}

void da_push(int value, DynamicArray *array)
{

    if (array->n_items + 1 == array->size)
    {
        _da_grow(array);
    }

    _da_add(array->n_items, value, array);
}

void da_insert(int index, int value, DynamicArray *array)
{
    if (array->n_items + 1 == array->size)
    {
        _da_grow(array);
    }

    _da_add(index, value, array);
}

void da_remove(int index, DynamicArray *array)
{
    // If items only occupy a 1/3 of the array after removal of this item, shrink the array
    if (array->n_items - 1 <= ceil(array->size / 3))
    {
        _da_shrink(array);
    }

    _da_delete(index, array);
}

void print_array(DynamicArray *array)
{
    printf("\nArray\n---------\n[");
    for (int i = 0; i < array->size; i++)
    {
        // Dont print "removed" elements
        if (array->array[i] == INT_MIN || !array->array[i])
        {
            continue;
        }

        printf("%d", array->array[i]);
        if (array->array[i + 1])
        {
            printf(",");
        }
    }

    printf("]\n\n");
    printf("Number of items: %d\n", array->n_items);
    printf("Size of array: %d\n", array->size);
    printf("Array growth factor: %f\n", array->growth_factor);
}

int main(void)
{
    DynamicArray *array = new_dynamic_array();
    da_push(1, array);
    da_push(2, array);
    da_push(3, array);
    da_push(4, array);
    da_push(5, array);
    da_remove(2, array);
    da_remove(2, array);

    print_array(array);

    return 0;
}