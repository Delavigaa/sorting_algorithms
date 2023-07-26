#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @num1: the initial swapped integer.
 * @num2: The next integer to be swapped.
 */
void swap_ints(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * selection_sort - Integer arrays should be sorted in ascending order
 *                  using the selection sort algorithm.
 * @array:a collection of integers.
 * @size: the array's size in bytes.
 *
 * Description:the array is printed after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
