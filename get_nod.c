#include "shell.h"
list_t *add_node(list_t **first, const char *achstr, int num)
{
	list_t *new_head;

	if (!first)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memory_set((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (achstr)
	{
		new_head->str = _str_dup(achstr);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *first;
	*first = new_head;
	return (new_head);
}

list_t *add_node_end(list_t **first, const char *achstr, int num)
{
	list_t *new_node, *node;

	if (!first)
		return (NULL);

	node = *first;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memory_set((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (achstr)
	{
		new_node->str = _str_dup(achstr);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*first = new_node;
	return (new_node);
}

size_t prt_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

int delete_node(list_t **first, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!first || !*first)
		return (0);

	if (!index)
	{
		node = *first;
		*first = (*first)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *first;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *first;

	if (!head_ptr || !*head_ptr)
		return;
	first = *head_ptr;
	node = first;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
