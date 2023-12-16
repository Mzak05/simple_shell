#include "shell.h"
/**
 * list_len - determines length of linked list
 * @pt: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *pt)
{
	size_t i = 0;

	while (pt)
	{
		pt = pt->next;
		i++;
	}
	return (i);
}

/**
 * list_to_str - returns an array of strings of the list->str
 * @first: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_str(list_t *first)
{
	list_t *node = first;
	size_t i = list_len(first), j;
	char **strs;
	char *str;

	if (!first || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlength(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _str_copy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @pt: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *pt)
{
	size_t i = 0;

	while (pt)
	{
		_puts(convert_number(pt->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(pt->str ? pt->str : "(nil)");
		_puts("\n");
		pt = pt->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @caca: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char caca)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((caca == -1) || (*p == caca)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node - gets the index of a node
 * @first: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node(list_t *first, list_t *node)
{
	size_t i = 0;

	while (first)
	{
		if (first == node)
			return (i);
		first = first->next;
		i++;
	}
	return (-1);
}
