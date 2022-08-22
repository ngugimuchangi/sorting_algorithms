#include "sort.h"

/**
 * swap_ints - swaps two intergers
 * @array: array of integers
 * @index_1: index of first number
 * @index_2: index of second number
 *
 * Return: nothing
 */
void swap_ints(int *array, int index_1, int index_2)
{
	int temp_int = array[index_1];

	array[index_1] = array[index_2];
	array[index_2] = temp_int;
}

/**
 * sift_down - function to arrange heap
 * @array: array to sort
 * @start: start of the array
 * @end: end of the array
 * @size: number of elements in the entire heap / array
 *
 * Description: shift current node to its right
 *		position in the heap
 * Return: nothing
 */
void sift_down(int *array, int start, int end, int size)
{
	int root = start, l_child, swap;

	for (l_child = (root * 2) + 1; l_child <= end; l_child = (root * 2) + 1)
	{
		swap = root;

		if (array[swap] < array[l_child])
			swap = l_child;
		if (l_child + 1 <= end && array[swap] < array[l_child + 1])
			swap = l_child + 1;
		if (swap == root)
			return;
		swap_ints(array, root, swap);
		print_array(array, size);
		root = swap;
	}
}

/**
 * heapify - function to arrange the array into a max heap
 * @array: array of integers to heapify
 * @size: size of the array
 *
 * Return: nothing
 */
void heapify(int *array, int size)
{
	int start;

	for (start = (size - 2) / 2; start >= 0; start--)
		sift_down(array, start, size - 1, size);
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Description: sorts an array of integers using the
 *		heap sort algorithm
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array && size > 2)
	{
		heapify(array, (int) size);

		i = size - 1;
		while (i > 0)
		{
			swap_ints(array, 0, i);
			i--;
			sift_down(array, 0, i, size);
		}
	}
}
