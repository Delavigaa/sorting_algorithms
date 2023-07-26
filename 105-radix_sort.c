#include "sort.h"

/**
 * get_max - Find the largest integer in an array.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Return: The array's biggest integer is.
 */
int get_max(int *array, int size)
{
    int max_value, i;

    for (max_value = array[0], i = 1; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    return max_value;
}

/**
 * radix_counting_sort - An integer array's significant digits should be sorted.
 *                       in ascending order using the counting sort algorithm.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * @sig: The sort key is the significant digit..
 * @buff: a buffer where the sorted array is kept.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / sig) % 10] += 1;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        buff[count[(array[i] / sig) % 10] - 1] = array[i];
        count[(array[i] / sig) % 10] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = buff[i];
}

/**
 * radix_sort - Integer arrays should be sorted ascending.
 *              order using the radix sort algorithm.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Description: the LSD radix sort method is implemented. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    int max_value, sig, *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    max_value = get_max(array, size);
    for (sig = 1; max_value / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buff);
        print_array(array, size);
    }

    free(buff);
}
