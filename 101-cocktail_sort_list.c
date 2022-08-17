#include "sort.h"

/**
 * swap_nodes_forward - rearranges nodes in a linked list
 * @list: head of linked list
 * @prev: previous element
 * @current: current element
 * @next: next element
 *
 * Description: performs a forward three-way swap between nodes
 * of a doubly linked list
 *
 * Return: nothing
 */
void swap_nodes_forward(listint_t **list, listint_t *prev,
		listint_t *current, listint_t *next)
{
	next = current->next;
	prev = current->prev;
	current->next = next->next;
	current->prev = next;
	next->prev = prev;
	if (prev)
		prev->next = next;
	else
		*list = next;
	if (next->next)
		next->next->prev = current;
	next->next = current;
}

/**
 * swap_nodes_backwards - rearranges nodes in a linked list
 * @list: head of linked list
 * @prev: previous element
 * @current: current element
 * @next: next element
 *
 * Description: performs a backwards three-way swap between nodes
 * of a doubly linked list
 *
 * Return: nothing
 */
void swap_nodes_backwards(listint_t **list, listint_t *prev,
		listint_t *current, listint_t *next)
{
	next = current->next;
	prev = current->prev;
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
}

/**
 * cocktail_sort_list - sorts doubly linked list
 * @list: head of the list
 *
 * Description: sorts a linked list of integers in ascedning order
 * using cocktail sort algorithm
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int flag = 1;

	if (!list || !(*list))
		return;

	temp = *list;
	while (flag == 1)
	{
		flag = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes_forward(list, temp->prev, temp, temp->next);
				print_list(*list);
				flag = 1;
				continue;
			}
			temp = temp->next;
		}

		flag = 0;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes_backwards(list, temp->prev, temp, temp->next);
				print_list(*list);
				flag = 1;
				continue;
			}
			temp = temp->prev;
		}
	}
}
