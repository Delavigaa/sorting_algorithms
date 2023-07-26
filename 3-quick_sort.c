#include "sort.h"

void swap_ints(int *num1, int *num2);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - In an array, swap two integers..
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
 * lomuto_partition - a subset of an array of integers in the following to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: the integer array.
 * @size: The array's dimensions.
 * @left: The subset's starting index is used to sort.
 * @right: The subset's final index to order.
 *
 * Return: the last index for partitioning.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return above;
}

/**
 * lomuto_sort - Recursion is used to implement the quicksort algorithm..
 * @array: a set of integers in an array.
 * @size: The array's dimensions.
 * @left: The array partition order's initial index.
 * @right: The array partitioning order's last index.
 *
 * Description: utilises the Lomuto partitioning method.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Integer arrays should be sorted ascending.
 *              using the quicksort method to arrange.
 * @array: array of int.
 * @size:  size of  array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
