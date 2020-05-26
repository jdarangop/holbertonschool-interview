#include "lists.h"


/**
 * len - find the lenght of the linked list.
 * @head: head of the linked list.
 * Return: The lenght of the linked list.
 */
int len(listint_t *head)
{
	int counter = 0;

	for (; head != NULL; head = head->next)
	{
		counter++;
	}
	return (counter);
}

/**
 * is_palindrome - check if a linked list is palindrome.
 * @head: head of the linked list.
 * Return: 1 if it is palindrome, 0 if doesn't
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int i, j, lenght, *numbers;

	if (*head == NULL)
		return (0);
	lenght = len(*head);
	numbers = malloc(sizeof(int) * lenght);
	for (i = 0; i < lenght; i++)
	{
		numbers[i] = current->n;
		current = current->next;
	}
	for (i = 0, j = lenght - 1; i < j; i++, j--)
	{
		if (numbers[i] != numbers[j])
		{
			free(numbers);
			return (0);
		}
	}
	free(numbers);
	return (1);
}
