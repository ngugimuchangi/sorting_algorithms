#include "sort.h"

/**
 * insertion_sort_list - function to sort doubly linked list
 * @list: head of the list
 *
 * Description: sorts a doubly linked list of integer data
 * in ascending order using insert sort algorithm
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current, *next, *prev;

	if (list && *list)
	{
		temp = (*list)->next;
		while (temp)
		{
			current = temp;
			prev = current->prev;
			temp = temp->next;
			while (prev && prev->n > current->n)
			{
				next = current->next;
				current->next = prev;
				current->prev = prev->prev;
				prev->next = next;
				if (next)
					next->prev = prev;
				if (prev->prev)
					prev->prev->next = current;
				else
					*list = current;
				prev->prev = current;
				print_list(*list);
				prev = current->prev;
			}
		}
	}
}
