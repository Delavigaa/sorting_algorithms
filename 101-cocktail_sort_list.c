#include "sort.h"

/**
 * swap_node_ahead - Replace a node in a doubly-linked list of type listint_t
 *                   integer list with the node preceding it.
 * @list: a pointer to the first integer in a doubly-linked list.
 * @tail: a pointing device to the doubly-linked list's tail.
 * @current: a reference to the cocktail shaker algorithm's current swapping node.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = tmp;
	tmp->next = *current;
	*current = tmp;
}

/**
 * swap_node_behind - Replace a node in a doubly-linked listint_t
 *                    list of integers and the node that follows it.
 * @list: a pointer to the first integer in a doubly-linked list.
 * @tail: a pointing device to the doubly-linked list's tail.
 * @current: a reference to the cocktail shaker algorithm's current swapping node.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*current = tmp;
}

/**
 * cocktail_sort_list - a doubly-linked list of integers named listint_t, sorted in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: a pointer to the head of a doubly-linked list of type listint_t.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_ahead(list, &tail, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_behind(list, &tail, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
