#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 *
 * Return: nothing
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: sorts array of integers using shell sorts algorithm
 * and employs Knuth interval sequence to find the suitable gaps
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, flag;

	if (array && size > 2)
	{
		for (gap = 1; gap < (size / 3);)
			gap = gap * 3 + 1;
		for (; gap > 0; gap /= 3)
		{
			flag = 0;
			for (i = gap; i < size; i++)
			{
				j = i;
				while (j >= gap && array[j - gap] > array[j])
				{
					swap_ints(array + j, array + (j - gap));
					j -= gap;
					flag = 1;
				}
			}
			print_array(array, size);
			if (!flag)
				break;
		}
	}
}
