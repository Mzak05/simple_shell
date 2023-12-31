#include "shell.h"

int is_chain_del(info_type *infffo, char *bufbuf, size_t *p)
{
	size_t j = *p;

	if (bufbuf[j] == '|' && bufbuf[j + 1] == '|')
	{
		bufbuf[j] = 0;
		j++;
		infffo->cmd_buf_type = CMD_OR;
	}
	else if (bufbuf[j] == '&' && bufbuf[j + 1] == '&')
	{
		bufbuf[j] = 0;
		j++;
		infffo->cmd_buf_type = CMD_AND;
	}
	else if (bufbuf[j] == ';')
	{
		bufbuf[j] = 0; 
		infffo->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}


void check_chain(info_type *infffo, char *bufbuf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (infffo->cmd_buf_type == CMD_AND)
	{
		if (infffo->status)
		{
			bufbuf[i] = 0;
			j = len;
		}
	}
	if (infffo->cmd_buf_type == CMD_OR)
	{
		if (!infffo->status)
		{
			bufbuf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

int replace_alias(info_type *infffo)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(infffo->alias, infffo->argv[0], '=');
		if (!node)
			return (0);
		free(infffo->argv[0]);
		p = _str_chr(node->str, '=');
		if (!p)
			return (0);
		p = _str_dup(p + 1);
		if (!p)
			return (0);
		infffo->argv[0] = p;
	}
	return (1);
}


int replace_vars_str(info_type *infffo)
{
	int i = 0;
	list_t *node;

	for (i = 0; infffo->argv[i]; i++)
	{
		if (infffo->argv[i][0] != '$' || !infffo->argv[i][1])
			continue;

		if (!_str_comp(infffo->argv[i], "$?"))
		{
			replacestr(&(infffo->argv[i]),
				_str_dup(convert_number(infffo->status, 10, 0)));
			continue;
		}
		if (!_str_comp(infffo->argv[i], "$$"))
		{
			replacestr(&(infffo->argv[i]),
				_str_dup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(infffo->env, &infffo->argv[i][1], '=');
		if (node)
		{
			replacestr(&(infffo->argv[i]),
				_str_dup(_str_chr(node->str, '=') + 1));
			continue;
		}
		replacestr(&infffo->argv[i], _str_dup(""));

	}
	return (0);
}


int replacestr(char **previous, char *next)
{
	free(*previous);
	*previous = next;
	return (1);
}
