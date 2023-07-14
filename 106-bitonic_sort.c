#include "sort.h"

void bitonic_recursive_sort(int *array, int low, int count,
							int dir, size_t size);
void bitonic_merge(int *array, int low, int count, int dir, size_t size);
void compare_and_swap(int *array, int i, int j, int dir);

/**
 * bitonic_sort - entry point
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_recursive_sort(array, 0, size, 1, size);
}

/**
 * bitonic_recursive_sort - sort an array of integers in specific order
 * @array: array to sort
 * @low: index of the first element
 * @count: number of elements to sort
 * @dir: direction of the sort
 * @size: size of the array
 * Return: nothing
 */

void bitonic_recursive_sort(int *array, int low, int count,
							int dir, size_t size)
{
	int k;

	if (count <= 1)
		return;
	k = count / 2;
	printf("Merging [%d/%d] (%s):\n",
		   count, (int)size, (dir == 1) ? "UP" : "DOWN");
	print_array(array + low, count);
	bitonic_recursive_sort(array, low, k, 1, size);
	bitonic_recursive_sort(array, low + k, k, 0, size);
	bitonic_merge(array, low, count, dir, size);
	printf("Result [%d/%d] (%s):\n", count,
		   (int)size, (dir == 1) ? "UP" : "DOWN");
	print_array(array + low, count);
}

/**
 * bitonic_merge - merge two subarrays
 * @array: array to sort
 * @low: index of the first element
 * @count: number of elements to sort
 * @dir: direction of the sort
 * @size: size of the array
 * Return: nothing
 */
void bitonic_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, k;

	if (count <= 1)
		return;

	k = count / 2;
	i = k;

	for (i = low; i < low + k; i++)
		compare_and_swap(array, i, i + k, dir);

	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}

/**
 * compare_and_swap - compare and swap two elements in an array
 * @array: - array to sort
 * @i: index of the first element
 * @j: index of the second element
 * @dir: direction of the sort
 * Return: nothing
 */
void compare_and_swap(int *array, int i, int j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
