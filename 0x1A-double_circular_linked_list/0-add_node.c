#include "list.h"

/**
 * add_node_end - add a node on the end.
 * @list: Double linked list.
 * @str: string value in the new node.
 *
 * Return: Memory addres to the new node.
 */
List *add_node_end(List **list, char *str)
{
	List *current, *new_node;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	current = *list;
	if (*list == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*list = new_node;
	}
	else
	{
		while (current->next != NULL && current->next != *list)
		{
			current = current->next;
		}
		new_node->prev = current;
		current->next = new_node;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - add a node on the beginning.
 * @list: Double linked list.
 * @str: string value in the new node.
 *
 * Return: Memory addres to the new node.
 */
List *add_node_begin(List **list, char *str)
{
	List *current, *new_node;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if (*list == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		current = *list;
		while (current->next != NULL && current->next != *list)
		{
			current = current->next;
		}
		if (current->prev == NULL)
			current->prev = new_node;
		new_node->prev = current;
		new_node->next = *list;
		(*list)->prev = new_node;
		current->next = new_node;
	}
	*list = new_node;

	return (new_node);
}
