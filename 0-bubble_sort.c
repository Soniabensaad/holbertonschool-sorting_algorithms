#include "sort.h"
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void bubble_sort(int *array, size_t size)
{
    int swap;
    size_t i, j;
    if (!array || !size)
    {
        return;
    }
    
    for ( i = 0; i < size - 1 ; i++)
    {
    
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
                print_array(array, size);
                
            }
           
            
            
        }
        

    }
    
}