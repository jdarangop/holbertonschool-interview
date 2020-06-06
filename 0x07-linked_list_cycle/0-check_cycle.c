#include "lists.h"

/**
 * check_cycle - check if there is a cycle in the linked list.
 * @list: Linked list to be checked.
 *
 * Return: 1 if there is, 0 if doesn't.
 */

int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	slow = list;
	fast = list;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
