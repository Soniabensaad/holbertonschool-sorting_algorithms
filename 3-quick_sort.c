#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void swap(int *m, int *n)
{
    int swapi = *m;
    *m = *n;
    *n = swapi;
    
}
int partition (int array[], int start, int end)
{
    int pivot = array[end];
    int i = (start - 1);
    for(int  j = start; j <= end - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        
    }
    swap(&array[i + 1], &array[end]);
    return (i + 1);
}
void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
    

}
void quick_sort(int *array, size_t size)
{
    if (!size || !array)
    {
        return;
    }
    quickSort(array, 0, size - 1);
    
}
