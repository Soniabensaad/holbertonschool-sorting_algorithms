#include "sort.h"

/**
* partition - partition schema for quicksort algorithm
* @array: Array to sort
* @start: lowest index of array
* @end: highest index of array
* Return: index of pivot
*/

int partition(int *array, int start, int end)
{
	int pivot, i, j, t;
	static int  size, k;
    
	if (k == 0)
		size = end + 1, k++;
	pivot = array[end];
	i = start;
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				t = array[i];
				array[i] = array[j];
				array[j] = t;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		t = array[i];
		array[i] = array[end];
		array[end] = t;
		print_array(array, size);
	}

	return (i);
}

/**
* qs - Quicksort recursive function
* @array: array to sort
* @start: lowest index
* @end: highest index
*/

void qs(int *array, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end);
		qs(array, start, pivot - 1);
		qs(array, pivot + 1, end);
	}
}


/**
* quick_sort - sorts array using quicksort algorithm
* @array: Array to sort
* @size: Size of array to sort
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	qs(array, 0, size - 1);
}
