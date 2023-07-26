#include "sort.h"

/**
 * swap_ints - In an array, swap two integers..
 * @a: the initial swapped integer.
 * @b: swapping the second integer.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * max_heapify - create a whole binary heap from a binary tree.
 * @array: a binary tree represented by an array of integers.
 * @size: The array's or tree's size.
 * @base_idx: the number in the tree's root row.
 * @root_idx: the binary tree's base node.
 *
 * Description: carries out the heap sort algorithm's max-heapify operation.
 */
void max_heapify(int *array, size_t size, size_t base_idx, size_t root_idx)
{
    size_t left_idx, right_idx, largest_idx;

    left_idx = 2 * root_idx + 1;
    right_idx = 2 * root_idx + 2;
    largest_idx = root_idx;

    if (left_idx < base_idx && array[left_idx] > array[largest_idx])
        largest_idx = left_idx;
    if (right_idx < base_idx && array[right_idx] > array[largest_idx])
        largest_idx = right_idx;

    if (largest_idx != root_idx)
    {
        swap_ints(array + root_idx, array + largest_idx);
        print_array(array, size);
        max_heapify(array, size, base_idx, largest_idx);
    }
}

/**
 * heap_sort - Integer arrays should be sorted ascending.
 *             heap sorting to determine order.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Description: the sift-down heap sort technique is implemented.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        max_heapify(array, size, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swap_ints(array, array + i);
        print_array(array, size);
        max_heapify(array, size, i, 0);
    }
}
