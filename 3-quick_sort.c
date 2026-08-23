#include "sort.h"
/**
 * partition - partition and sorts the partition for quicksort
 * @array: the array to partition
 * @size: size of the array
 * @left: index of the first element
 * @right: index of the last element
 * Return: index pivot
 */
int partition(int *array, size_t size, int left, int right)
{
	int pivot, low, current, temp;

	pivot = array[right];
	low = left - 1;
	current = left;
	while (current < right)
	{
		if (array[current] < pivot)
		{
			low++;
			if (low != current)
			{
				temp = array[low];
				array[low] = array[current];
				array[current] = temp;
				print_array(array, size);
			}
		}
		current++;
	}
	low++;
	if (array[low] != pivot)
	{
		temp = array[low];
		array[low] = array[current];
		array[current] = temp;
		print_array(array, size);
	}
	return (low);
}
/**
 * quick_sort_recursion - sorts a partition of an array
 * @array: the array to sort
 * @size: size of the array
 * @left: starting index
 * @right: ending index
 */
void quick_sort_recursion(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, size, left, right);
		quick_sort_recursion(array, size, left, pivot - 1);
		quick_sort_recursion(array, size, pivot + 1, right);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quicksort algorithm (Lomuto partition scheme)
 * @array: the array to sort
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, (int)size - 1);
}
