#include "shell.h"
/**
 * add_node - adds a node to the start of the list
 * @first: address of pointer to first node
 * @achstr: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
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

/**
 * add_node_end - adds a node to the end of the list
 * @first: address of pointer to first node
 * @achstr: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
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

/**
 * prt_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
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

/**
 * delete_node - deletes node at given index
 * @first: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
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

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to first node
 *
 * Return: void
 */
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