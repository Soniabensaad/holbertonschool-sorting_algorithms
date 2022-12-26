#include "sort.h"
/**
 * Merge_side - sorts and merges the sub arrays in source
 * @start: starting index 
 * @middle: middle index
 * @end: end index
 * @destination: destination for data
 * @source: source of data
 *
 * Return: void
 */
void Merge_side(size_t start, size_t middle, size_t end, int *destination, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			destination[k] = source[i];
			i++;
		}
		else
		{
			destination[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(destination + start, end - start);
}

/**
 * Merge_split - splits the array 
 * @start: starting index 
 * @end: end index 
 * @array: the array to sort
 * @ptr: a copy of the array
 *
 * Return: void
 */
void Merge_split(size_t start, size_t end, int *array, int *ptr)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	Merge_split(start, middle, array,ptr);
	Merge_split(middle, end, array, ptr);
	Merge_side(start, middle, end, array, ptr);
	for (middle = start; middle < end; middle++)
		ptr[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *ptr;

	if (array == NULL || size < 2)
		return;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return;
	for (i = 0; i < size; i++)
		ptr[i] = array[i];
	Merge_split(0, size, array, ptr);
	free(ptr);
}