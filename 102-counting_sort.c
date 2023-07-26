#include "sort.h"

/**
 * get_max - Find the highest value in an integer array..
 * @array: a collection of integers.
 * @size: the array's size in bytes.
 *
 * Return: The array's biggest integer is.
 */
int get_max(int *array, int size)
{
	int max_val, i;

	for (max_val = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	return (max_val);
}

/**
 * counting_sort - Integer arrays should be sorted in ascending order.
 *                 using the counting sort algorithm.
 * @array: a collection of integers.
 * @size: how big the array is.
 *
 * Description: after it has been configured, prints the counting array..
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max_val, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_val = get_max(array, size);
	count = malloc(sizeof(int) * (max_val + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max_val + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i < (max_val + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max_val + 1);

	for (i = size - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
