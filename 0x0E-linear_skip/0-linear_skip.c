#include "search.h"


/**
 * linear_skip - search an element in a skip list.
 * @list: pointer to the head of the list.
 * @value: value to search for.
 *
 * Return: the index where the value was found.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = list, *post, *tmp;
	int flag = 0;

	if (list == NULL || !value)
		return (NULL);
	post = list->express;
	while (post != NULL)
	{
		if (flag == 0)
			printf("Value checked at index [%i] = [%i]\n",
			(int)post->index, (int)post->n);
		if (post->n == value)
			return (post);
		else if (post->n > value || post->next == NULL || flag == 1)
		{ printf("Value found between indexes [%i] and [%i]\n",
			(int)prev->index, (int)post->index);
			tmp = prev;
			while (tmp != NULL && tmp->index <= post->index)
			{ printf("Value checked at index [%i] = [%i]\n",
				(int)tmp->index, (int)tmp->n);
				if (tmp->n == value)
					return (tmp);
				tmp = tmp->next;
			}
			return (NULL);
		}
		else if (post->express == NULL)
		{ tmp = post;
			while (tmp->next != NULL)
				tmp = tmp->next;
			prev = post;
			post = tmp;
			flag = 1;
		}
		else
		{ prev = post;
			post = post->express;
		}
	}
	return (NULL);
}
