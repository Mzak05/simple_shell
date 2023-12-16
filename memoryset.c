#include "shell.h"
char *_memory_set(char *ptr, char by, unsigned int nb)
{
	unsigned int i;

	for (i = 0; i < nb; i++)
		ptr[i] = by;
	return (ptr);
}
void str_free(char **sos)
{
	char **a = sos;

	if (!sos)
		return;
	while (*sos)
		free(*sos++);
	free(a);
}

void *_realloc(void *ptr, unsigned int oldsz, unsigned int newsz)
{
	char *p;

	if (!ptr)
		return (malloc(newsz));
	if (!newsz)
		return (free(ptr), NULL);
	if (newsz == oldsz)
		return (ptr);

	p = malloc(newsz);
	if (!p)
		return (NULL);

	oldsz = oldsz < newsz ? oldsz : newsz;
	while (oldsz--)
		p[oldsz] = ((char *)ptr)[oldsz];
	free(ptr);
	return (p);
}
