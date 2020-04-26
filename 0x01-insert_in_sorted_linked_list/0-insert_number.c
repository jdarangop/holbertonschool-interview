#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert a Node in a sorted linked list
 *
 * @head: Pointer of the head pointer.
 * @number: Number to insert.
 *
 * Return: The address of the new node or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current = *head;

	if (**head == NULL || *head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;

	if (number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		/*return (*head);*/
	}
	else
	{
		while (current->next != NULL && current->next->n < number)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
	return (new_node);
}
