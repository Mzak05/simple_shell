#include "shell.h"
char **get_env(info_type *infffo)
{
	if (!infffo->environ || infffo->env_changed)
	{
		infffo->environ = list_to_str(infffo->env);
		infffo->env_changed = 0;
	}

	return (infffo->environ);
}

int _unsetenv(info_type *infffo, char *varia)
{
	list_t *node = infffo->env;
	size_t i = 0;
	char *ptr;

	if (!node || !varia)
		return (0);

	while (node)
	{
		ptr = starts_with(node->str, varia);
		if (ptr && *ptr == '=')
		{
			infffo->env_changed = delete_node(&(infffo->env), i);
			i = 0;
			node = infffo->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (infffo->env_changed);
}
int _setenviro(info_type *infffo, char *varia, char *val)
{
	char *buffer = NULL;
	list_t *node;
	char *ptr;

	if (!varia || !val)
		return (0);

	buffer = malloc(_strlength(varia) + _strlength(val) + 2);
	if (!buffer)
		return (1);
	_str_copy(buffer, varia);
	_str_cat(buffer, "=");
	_str_cat(buffer, val);
	node = infffo->env;
	while (node)
	{
		ptr = starts_with(node->str, varia);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buffer;
			infffo->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(infffo->env), buffer, 0);
	free(buffer);
	infffo->env_changed = 1;
	return (0);
}
