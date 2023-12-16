#include "shell.h"
/**
 * _myenvir - prcuenv
 * @infffo: Stru
 * Return: Always 0
 */
int _myenvir(info_type *infffo)
{
	prt_list_str(infffo->env);
	return (0);
}

/**
 * _get_env - envvar
 * @infffo: Stru
 * @envname: envvar
 * Return:  val
 */
char *_get_env(info_type *infffo, const char *envname)
{
	list_t *node = infffo->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, envname);
		if (x && *x)
			return (x);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - newenvvar
 * @infffo: Stru
 *  Return: Always 0
 */
int _mysetenv(info_type *infffo)
{
	if (infffo->argc != 3)
	{
		_eput_str("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenviro(infffo, infffo->argv[1], infffo->argv[2]))
		return (0);
	return (1);
}

/**
 * _my_unsetenv - rmenvvar
 * @infffo: Stru
 *  Return: Always 0
 */
int _my_unsetenv(info_type *infffo)
{
	int i;

	if (infffo->argc == 1)
	{
		_eput_str("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= infffo->argc; i++)
		_unsetenv(infffo, infffo->argv[i]);

	return (0);
}

/**
 * p_env_list - fill env
 * @infffo: Stru
 * Return: Always 0
 */
int p_env_list(info_type *infffo)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	infffo->env = node;
	return (0);
}
