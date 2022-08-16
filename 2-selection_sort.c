#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * @array: array to sort
 * @size: size of array
 *
 * Description: sorts an array of integers in ascending order
 * using selection sort algorithm
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	int *temp_array = array, temp_int;
	size_t temp_size = size, i, j, index;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i, index = i; j < size; j++)
			if (temp_array[j] < temp_array[index])
				index = j;
		if (index != i)
		{
			temp_int = temp_array[index];
			array[index] = array[i];
			array[i] = temp_int;
			print_array(temp_array, temp_size);
		}
	}
}
