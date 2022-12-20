
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
    if (!array)
    {
        return;
    }
    
    for (i = 0; i < size -1 ; i++)
    {
        min = i;
        for (min = i + 1, j = size - 1; i< j; j--)
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
