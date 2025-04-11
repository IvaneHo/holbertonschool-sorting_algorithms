#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
			swap_nodes(list, temp->prev, temp);
		current = current->next;
	}
}
