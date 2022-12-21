#include "sort.h"

/**
 * main - Entry point
 *
 * Return: 
 */
void swap(int *m, int *n)
{
    int swapi = *m;
    *m = *n;
    *n = swapi;
    
}
int partition (int array[], int start, int end, size_t size)
{
    int pivot = array[end];
    int i = (start - 1);
    for(int  j = start; j <= end - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            if (start != end)
				print_array(array, size);
        }
        
    }
    swap(&array[i + 1], &array[end]);
    if (start != end)
				print_array(array, size);
   
    return (i + 1);
}
void quickSort(int array[], int start, int end, size_t size)
{
    if (start < end)
    {
        int pivot = partition(array, start, end, size);
        quickSort(array, start, pivot - 1, size);
        quickSort(array, pivot + 1, end, size);
    }
    

}
void quick_sort(int *array, size_t size)
{
    if (!size || !array)
    {
        return;
    }
    quickSort(array, 0, size - 1, size);
    
}

