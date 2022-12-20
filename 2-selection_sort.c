
#include "sort.h"
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min ;
    int swap;
    if (!array || !size)
    {
        return;
    }
    
    for (i = 0; i < size ; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
           {
                min = j;
            }
            if (min != i)
            {
                swap = array[i];
                array[i] = array[min];
                array[min] = swap;
                print_array(array, size);

            }
        }    
    }

}
