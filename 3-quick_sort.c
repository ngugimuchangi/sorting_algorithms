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
	if (size > 1)
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
	int temp_int, index, i;

	for (i = start, index = start; i < end; i++)
		if (array[i] <= array[end])
		{
			temp_int = array[i];
			array[i] = array[index];
			array[index] = temp_int;
			index++;
			print_array(array, size);
		}

	temp_int = array[end];
	array[end] = array[index];
	array[index] = temp_int;

	if (start == end)
		print_array(array, size);

	return (index);
}
