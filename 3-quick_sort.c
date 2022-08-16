#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * @array: array to sort
 * @size: size of the array
 *
 * Description: sorts an array of integers in asceding order
 * using quick sort algorithm
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - implementation of quicksort algorithm
 * @array: array to sort
 * @start: start of array
 * @end: end of array
 * @size: size of array
 *
 * Return: nothing
 */
void quicksort(int *array, int start, int end, size_t size)
{
	int index;

	if (start < end)
	{
		index = partition_array(array, start, end, size);
		quicksort(array, start, index - 1, size);
		quicksort(array, index + 1, end, size);
	}
}

/**
 * partition_array - function that divides array into two
 * @array: array to partition
 * @start: starting point of the array
 * @end: end point of the array
 * @size: size of array
 *
 * Decription: divides array into two parts using Lomuto
 * partition scheme i.e. using the last element as the pivot
 *
 * Return: index of the pivot
 */
int partition_array(int *array, int start, int end, size_t size)
{
	int i, temp_int, index, pivot = array[end];

	for (i = start, index = start - 1; i < end; i++)
		if (array[i] <= pivot)
		{
			index++;
			temp_int = array[index];
			array[index] = array[i];
			array[i] = temp_int;
			if (index < i)
				print_array(array, size);
		}

	index++;
	array[end] = array[index];
	array[index] = pivot;
	if (index < end)
		print_array(array, size);

	return (index);
}
