#include "sort.h"
int _Maximum(int *array, size_t size)
{
    int k = 0;
    size_t i;
    for (i = 0; i < size; i++)
    {
        if (array[i] > k)
        {
            k = array[i];
        }
        
    }
    return (k);
    
}
int *_memset(int size)
{
    int *temp =NULL;
    int i;
    temp = malloc((size) * sizeof(int));
    for (i = 0; i < size; i++)
    {
        temp[i] = 0;
    }
    return (temp);
}
void counting_sort(int *array, size_t size)
{
    size_t i, j;
    int k = 0;
    int *temp = NULL, *sort = NULL;
    if (size < 2 || !array)
    {
        return;
    }
    k = _Maximum(array, size);
    temp = _memset(k + 1);
    if (!temp)
    {
        return;
    }
    
    
    for (i = 0; i < size; i++)
    {
        for (j = 0; (int)j < k + 1; i++)
        {
            if ((int)j == array[i])
            {
                temp[j]++;
            }
            
        }
        
    }
    for (i = 0; (int)i < k ; i++)
    {
        temp[i + 1] = temp[i] + temp[i + 1];
    
    }
    print_array(temp, k + 1);
    sort = malloc(size * sizeof(int));
    if (!sort)
    {
        free(temp);
        return;
    }
    
    for (i = 0; i < size; i++)
    {
        sort[temp[array[i]] - 1] = array[i];
        temp[array[i]]--;
    }
    for (j = 0; j < size; j++)
    {
        array[j] = sort[j];
    }

    free(sort);
    free(temp);
    

}
