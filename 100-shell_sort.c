#include "sort.h"

/**
 * swap_ints - In an array, swap two integers..
 * @a: the initial swapped integer.
 * @b: The next integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Integer arrays should be sorted ascending.
 *              order using the shell sort algorithm.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = size / 3; interval > 0; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_ints(array + j, array + (j - interval));
				j -= interval;
			}
		}
	}
}
