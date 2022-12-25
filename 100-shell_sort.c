#include "sort.h"
void shell_sort(int *array, size_t size)
{
   long unsigned int  gap = size /2 , i, j;
     int tpr;
   
	if (!array || size < 2)
    {
		return;
    }
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            tpr = array[i];
            for (j = j; j>= gap && array[j - gap] > tpr; j = -gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = tpr;
            

        }
        
        
    }
    gap = gap *3 +1;
    print_array(array, size);
}   