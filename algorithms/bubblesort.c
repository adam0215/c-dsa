#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int test = *a;
    *a = *b;
    *b = test;
}

void bubblesort(int array[], int array_len)
{
    bool has_swapped = false;

    do
    {
        has_swapped = false;
        for (int i = 0; i < array_len; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                has_swapped = true;
            }
        }

    } while (has_swapped);
}

void print_array(int array[], int array_len)
{
    for (int i = 0; i < array_len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int unsorted_array[] = {3, 7, 2, 5, 1, 4, 6, 8};
    int unsorted_array_len = sizeof(unsorted_array) / sizeof(int);

    print_array(unsorted_array, unsorted_array_len);

    bubblesort(unsorted_array, unsorted_array_len);

    print_array(unsorted_array, unsorted_array_len);
}