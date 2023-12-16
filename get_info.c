#include "shell.h"
void clear_info(info_type *infffo)
{
	infffo->arg = NULL;
	infffo->argv = NULL;
	infffo->path = NULL;
	infffo->argc = 0;
}

void set_info(info_type *infffo, char **argv)
{
	int i = 0;

	infffo->fname = argv[0];
	if (infffo->arg)
	{
		infffo->argv = str_split(infffo->arg, " \t");
		if (!infffo->argv)
		{

			infffo->argv = malloc(sizeof(char *) * 2);
			if (infffo->argv)
			{
				infffo->argv[0] = _str_dup(infffo->arg);
				infffo->argv[1] = NULL;
			}
		}
		for (i = 0; infffo->argv && infffo->argv[i]; i++)
			;
		infffo->argc = i;

		replace_alias(infffo);
		replace_vars_str(infffo);
	}
}

void free_info(info_type *infffo, int all)
{
	str_free(infffo->argv);
	infffo->argv = NULL;
	infffo->path = NULL;
	if (all)
	{
		if (!infffo->cmd_buf)
			free(infffo->arg);
		if (infffo->env)
			free_list(&(infffo->env));
		if (infffo->history)
			free_list(&(infffo->history));
		if (infffo->alias)
			free_list(&(infffo->alias));
		str_free(infffo->environ);
			infffo->environ = NULL;
		ptr_free((void **)infffo->cmd_buf);
		if (infffo->readfd > 2)
			close(infffo->readfd);
		_putchar(BUF_FLUSH);
	}
}
