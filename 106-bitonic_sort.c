#include "sort.h"

/**
 * swap_ints - In an array, swap two integers..
 * @a: the initial swapped integer.
 * @b: The next integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_merge - Sort an integer array to contain a bitonic sequence..
 * @array: An array of integers.
 * @size: The array's dimensions.
 * @start: The sequence's initial index in the array that will be sorted.
 * @seq: Size of the to-be-sorted sequence.
 * @flow: The order of sorting.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == UP && array[i] > array[i + jump]) ||
                (flow == DOWN && array[i] < array[i + jump]))
                swap_ints(array + i, array + i + jump);
        }
        bitonic_merge(array, size, start, jump, flow);
        bitonic_merge(array, size, start + jump, jump, flow);
    }
}

/**
 * bitonic_sequence - An integer array to a bitonic sequence conversion.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 * @start: the block's initial index in the bitonic construction sequence.
 * @seq: Block size in the bitonic construction sequence.
 * @flow: The order in which the bitonic sequence block should be sorted.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t cut = seq / 2;
    char *str = (flow == UP) ? "UP" : "DOWN";

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);

        bitonic_sequence(array, size, start, cut, UP);
        bitonic_sequence(array, size, start + cut, cut, DOWN);
        bitonic_merge(array, size, start, seq, flow);

        printf("Result [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);
    }
}

/**
 * bitonic_sort - Integer arrays should be sorted ascending.
 *                order using the bitonic sort algorithm.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Description: the array is printed after each swap. Only works for
 * size = 2^k where k >= 0 (i.e. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sequence(array, size, 0, size, UP);
}
