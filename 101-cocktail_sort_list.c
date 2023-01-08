#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void swaper(listint_t *x, listint_t *y)
{
    if (x->prev)
    {
        x->prev->next = y;
    }
     if (y->prev)
    {
        y->next->prev = x;
    }
    x->next = y->next;
    y->prev = x->prev;
    x->prev = y;
    y->next = x;

}
/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
listint_t *temp_traverse(listint_t *head, listint_t *temp, listint_t *list)
{
	while (temp && temp ->prev)
	{
		if (temp->n < temp->prev->n)
		{
			swaper(temp->prev, temp);
			if (temp->prev == NULL)
				list = temp;
			print_list(list);
		}
		else
		temp = temp->prev;
		if (temp->prev == NULL)
			head = temp;
	}
	return (head);
}
void cocktail_sort_list(listint_t **list)
{
   listint_t *temp, *head, *length;
	int i = 0, j = 0, swap = 1;

	if (!list || !*list)
		return;
	length = *list;
	for (i = 0; length; i++)
	{
		length = length->next;
	}
	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		swap = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swaper(head, head->next);
				swap++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				temp = head;
		}
		head = temp_traverse(head, temp, *list);
		*list = head;
		j++;
	}
}
