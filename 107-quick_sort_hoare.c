#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int start, int end);
void hoare_sort_recursive(int *array, size_t size, int start, int end); void quick_sort_hoare(int *array, size_t size);


/**
 * swap_ints - In an array, swap two integers..
 * @a: first int.
 * @b:  second int.
 */
void swap_ints(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - sorted subset of an integer array
 *                   according to the Hoare partition scheme.
 * @array: The collection of integers.
 * @size: how big the array is.
 * @start: The subset's starting index is used to sort.
 * @end: The subset's final index to order.
 *
 * Return: The last index of the partition.
 *
 * Description: utilises the partition's final component as its pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int start, int end)
{
	int pivot, idx_above, idx_below;
	pivot = array[end];

	for (idx_above = start - 1, idx_below = end + 1; idx_above < idx_below;)
	{
		do {
			idx_above++;
		} while (array[idx_above] < pivot);

		do {
			idx_below--;
		} while (array[idx_below] > pivot);

		if (idx_above < idx_below)
		{
			swap_ints(array + idx_above, array + idx_below);
			print_array(array, size);
		}
	}

	return (idx_above);
}

/**
 * hoare_sort_recursive - Recursion is used to implement the quicksort algorithm..
 * @array:Sorting an array of numbers.
 * @size: The array's dimensions.
 * @start: The array partition's initial beginning index.
 * @end: The array partition's final index in sequence.
 *
 * Description: utilises the Hoare partitioning method.
 */
void hoare_sort_recursive(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = hoare_partition(array, size, start, end);
		hoare_sort_recursive(array, size, start, part - 1);
		hoare_sort_recursive(array, size, part, end);
	}
}

/**
 * quick_sort_hoare - Integer arrays should be sorted ascending.
 *                    order using the quicksort algorithm.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort_recursive(array, size, 0, size - 1);
}
