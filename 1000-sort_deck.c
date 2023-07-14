#include <stdlib.h>
#include "deck.h"

/**
 * get_card_value - get the value of a card based on its kind and value
 *
 * @card: pointer to the card to get the value of
 * Return: int - value of the card
 */
int get_card_value(const card_t *card)
{
	int card_value = card->kind * 13;

	switch (card->value[0])
	{
	case 'A':
		card_value += 1;
		break;
	case 'J':
		card_value += 11;
		break;
	case 'Q':
		card_value += 12;
		break;
	case 'K':
		card_value += 13;
		break;
	case '1':
		card_value += (int)card->value[0] * 10 + (int)card->value[1] - 96;
		break;
	default:
		card_value += (int)card->value[0] - 48;
		break;
	}
	return (card_value);
}

/**
 * compare - compare two nodes in a doubly linked list
 * @node_one: first node to compare
 * @node_two: second node to compare
 * Return: int - difference between the two nodes
 */
int compare(deck_node_t *node_one, deck_node_t *node_two)
{
	int card_one_value = get_card_value(node_one->card);
	int card_two_value = get_card_value(node_two->card);

	return (card_one_value - card_two_value);
}

/**
 * swap_nodes - swap two nodes in a doubly linked list
 *
 * @head: pointer to the head of the list
 * @node_one: first node to swap
 * @node_two: second node to swap
 * Return: nothing
 */
void swap_nodes(deck_node_t **head, deck_node_t *node_one,
				deck_node_t *node_two)
{
	deck_node_t *temp = node_one->prev;

	node_one->next = node_two->next;
	if (node_two->next)
		node_two->next->prev = node_one;

	if (node_two->prev == node_one)
		node_one->prev = node_two;
	else
		node_one->prev = node_two->prev;

	node_one->prev->next = node_one;
	node_one->prev->prev = temp;
	if (temp)
		temp->next = node_two;
	else
		*head = node_two;
}

/**
 * sort_deck - sort a deck of cards
 * Used insertion sort algorithm
 *
 * @deck: head of the doubly linked list of cards to sort
 * Return: nothing
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *deck_tracker, *deck_back_tracker, *current_node, *temp;

	if (!(*deck))
		return;

	deck_tracker = (*deck)->next;

	while (deck_tracker)
	{
		temp = deck_tracker->next;
		current_node = deck_tracker;
		deck_back_tracker = deck_tracker->prev;
		while (deck_back_tracker && compare(current_node, deck_back_tracker) < 0)
		{
			swap_nodes(deck, deck_back_tracker, current_node);
			deck_back_tracker = current_node->prev;
		}
		deck_tracker = temp;
	}
}
