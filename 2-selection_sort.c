#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the selection sort algorithm
 * @array: the array to sort
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t min, tempidx, index;
	int temp = 0;

	min = tempidx = index = 0;
	if (array == NULL || size < 2)
		return;
	while (index < size - 1)
	{
		min = tempidx = index;
		tempidx++;
		while (tempidx < size)
		{
			
			if (array[tempidx] < array[min])
			{
				min = tempidx;
			}
			tempidx++;
		}
		if (min != index)
		{
			temp = array[index];
			array[index] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		index++;
	}
}
