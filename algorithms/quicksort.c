#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            swap(&array[i], &array[j]);
            i++;
        }

        swap(&array[i], &array[high]);
    }

    return i;
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);

        quicksort(array, low, high - 1);
        quicksort(array, low + 1, high);
    }
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

    quicksort(unsorted_array, 0, unsorted_array_len);

    print_array(unsorted_array, unsorted_array_len);

    return 0;
}