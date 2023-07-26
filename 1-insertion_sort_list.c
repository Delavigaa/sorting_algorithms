#include "sort.h"

/**
 * swap_nodes - In a listint_t doubly-linked list, switch two nodes.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: a pointing device at the doubly-linked list's head.
 * @n2: the following node to switch.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - a doubly linked list of integers is sorted
 *                       using the insertion sort algorithm.
 * @list: a pointer to the top of a list of numbers that is doubly linked.
 *
 * Description: the list is printed after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
