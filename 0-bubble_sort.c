#include "sort.h"

/**
 * bubble_sort - function that sort integers
 * @array: integer array
 * @size: size of the array
 *
 * Description: sorts an array of integers in ascending order
 * using bubble sort algorithm
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	int *temp_array = array, temp_int;
	size_t temp_size = size, i, j, flag;

	for (i = 0; i < temp_size; i++)
	{
		flag = 0;
		for (j = 0; j < temp_size - 1; j++)
			if (temp_array[j] > temp_array[j + 1])
			{
				temp_int = temp_array[j];
				temp_array[j] = temp_array[j + 1];
				temp_array[j + 1] = temp_int;
				flag = 1;
				print_array(temp_array, temp_size);
			}
		if (!flag)
			break;
	}
}
