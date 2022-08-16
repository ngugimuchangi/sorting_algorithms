#include "sort.h"

/**
 * quick_sort_hoare - function that sorts an array of integers
 * @array: array to sort
 * @size: size of the array
 *
 * Description: sorts an array of integers in asceding order
 * using quick sort algorithm
 *
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - implementation of quicksort algorithm
 * @array: array to sort
 * @start: start of array
 * @end: end of array
 * @size: size of array
 *
 * Return: nothing
 */
void quicksort_hoare(int *array, int start, int end, size_t size)
{
	int index;

	if (start < end)
	{
		index = partition_array_hoare(array, start, end, size);
		quicksort_hoare(array, start, index - 1, size);
		quicksort_hoare(array, index + 1, end, size);
	}
}

/**
 * partition_array_hoare - function that divides array into two
 * @array: array to partition
 * @start: starting point of the array
 * @end: end point of the array
 * @size: size of array
 *
 * Decription: divides array into two parts using Haore's
 * partition scheme i.e. using the last element as the pivot
 *
 * Return: index of the pivot
 */
int partition_array_hoare(int *array, int start, int end, size_t size)
{
	int i = start - 1, j = end, temp_int, pivot = array[end];

	while (i <= j)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i < j)
		{
			temp_int = array[i];
			array[i] = array[j];
			array[j] = temp_int;
			print_array(array, size);
		}
	}

	array[end] = array[i];
	array[i] = pivot;
	print_array(array, size);

	return (i);
}
