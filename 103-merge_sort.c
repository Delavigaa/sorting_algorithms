#include "sort.h"

/**
 * merge_subarr - Sort an integer subarray.
 * @subarr:a segment of a sortable array of numbers.
 * @buff: a buffer where the sorted subarray will be kept.
 * @front_idx: the array's front index.
 * @mid_idx: the array's middle index.
 * @back_idx: The array's back index.
 *
 * Description: carries out the merge-sort algorithm's merging phase..
 */
void merge_subarr(int *subarr, int *buff, size_t front_idx, size_t mid_idx, size_t back_idx)
{
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarr + front_idx, mid_idx - front_idx);

    printf("[right]: ");
    print_array(subarr + mid_idx, back_idx - mid_idx);

    for (i = front_idx, j = mid_idx; i < mid_idx && j < back_idx; k++)
        buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
    for (; i < mid_idx; i++)
        buff[k++] = subarr[i];
    for (; j < back_idx; j++)
        buff[k++] = subarr[j];
    for (i = front_idx, k = 0; i < back_idx; i++)
        subarr[i] = buff[k++];

    printf("[Done]: ");
    print_array(subarr + front_idx, back_idx - front_idx);
}

/**
 * merge_sort_recursive - Recursion is used to implement the merge sort algorithm..
 * @subarr: An array of integers with a subarray for sorting.
 * @buff: a buffer for keeping the sorted outcome.
 * @front_idx: The subarray's front index is used.
 * @back_idx: The subarray's back index.
 *
 * Description: use the method for top-down merge sorting.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front_idx, size_t back_idx)
{
    size_t mid_idx;

    if (back_idx - front_idx > 1)
    {
        mid_idx = front_idx + (back_idx - front_idx) / 2;
        merge_sort_recursive(subarr, buff, front_idx, mid_idx);
        merge_sort_recursive(subarr, buff, mid_idx, back_idx);
        merge_subarr(subarr, buff, front_idx, mid_idx, back_idx);
    }
}

/**
 * merge_sort - Integer arrays should be sorted ascending.
 *              order using the merge sort algorithm.
 * @array: a collection of integers.
 * @size: the array's size in bytes.
 *
 * Description: use the method for top-down merge sorting.
 */
void merge_sort(int *array, size_t size)
{
    int *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}
