#include "sort.h"
/**
*bubble_sort - sorts and array of ints using bubble sort algo
*@array: the array of ints to sort
*@size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	int swap, temp;
	size_t counter;

	if (array == NULL)
		return;
	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		counter = 0;
		while ((counter + 1) < size)
		{
			if (array[counter] > array[counter + 1])
			{
				temp = array[counter + 1];
				array[counter + 1] = array[counter];
				array[counter] = temp;
				swap = 1;
				print_array(array, size);
			}
			counter++;
		}
	}
}
