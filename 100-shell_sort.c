#include "sort.h"
void shell_sort(int *array, size_t size)
{
    size_t gap , i, j;
    int tpr;
   
	if (!array || size < 2)
    {
		return;
    }
    gap = 1;
    while (gap < size)
		gap = (gap * 3) + 1;
    gap = (gap -1) /3;
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            tpr = array[i];
            for (j = i; j>= gap && array[j - gap] > tpr; j -=gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = tpr;
            

        }
        
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
    
    
}   

