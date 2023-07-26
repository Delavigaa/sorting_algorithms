#include "sort.h"

/**
 * swap_ints - In an array, swap two integers..
 * @a: First integer.
 * @b: Second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Integer arrays should be sorted in ascending order..
 * @array: Sorting an array of numbers.
 * @size: contain array size.
 *
 * Description: Prints the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, array_length = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < array_length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		array_length--;
	}
}
