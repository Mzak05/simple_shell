#include "shell.h"
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
