#include "sort.h"
/**
*insertion_sort_list - sorts a list using insertion sort
*@list: pointer to list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *min, *temp, *index;
	int sorted = 1;

	if (*list == NULL)
		return;
	index = *list;
	while (sorted == 1)
	{
		sorted = 0;
		while (index->next != NULL)
		{
			temp = index;
			index = index->next;
			min = index;
			while (min->n < temp->n && min->prev != NULL)
			{
				if (min->next != NULL)
					min->next->prev = temp;
				temp->next = min->next;
				min->next = temp;
				min->prev = temp->prev;
				if (min->prev == NULL)
				{
					*list = min;
					temp->prev = min;
				}
				else
				{
					temp->prev->next = min;
					temp->prev = min;
					temp = min->prev;
				}
				print_list(*list);
				sorted = 1;
			}
		}
	}
}
