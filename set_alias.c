#include "shell.h"
/**
 * _myhistory - displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @infffo: Structure containing potential arguments
 *  Return: Always 0
 */
int _myhistory(info_type *infffo)
{
	print_list(infffo->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @infffo: parameter struct
 * @achstr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_type *infffo, char *achstr)
{
	char *p, c;
	int ret;

	p = _str_chr(achstr, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node(&(infffo->alias),
		get_node(infffo->alias, node_starts_with(infffo->alias, achstr, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @infffo: parameter struct
 * @achstr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_type *infffo, char *achstr)
{
	char *p;

	p = _str_chr(achstr, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(infffo, achstr));

	unset_alias(infffo, achstr);
	return (add_node_end(&(infffo->alias), achstr, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _str_chr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @infffo: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myalias(info_type *infffo)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (infffo->argc == 1)
	{
		node = infffo->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; infffo->argv[i]; i++)
	{
		p = _str_chr(infffo->argv[i], '=');
		if (p)
			set_alias(infffo, infffo->argv[i]);
		else
			print_alias(node_starts_with(infffo->alias, infffo->argv[i], '='));
	}

	return (0);
}
