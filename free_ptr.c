#include "shell.h"
/**
 * ptr_free - frees a pointer and NULLs the address
 * @padr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int ptr_free(void **padr)
{
	if (padr && *padr)
	{
		free(*padr);
		*padr = NULL;
		return (1);
	}
	return (0);
}
