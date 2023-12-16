#include "shell.h"
/**
 **_memory_set - fills memory with a constant byte
 *@ptr: the pointer to the memory area
 *@by: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memory_set(char *ptr, char by, unsigned int nb)
{
	unsigned int i;

	for (i = 0; i < nb; i++)
		ptr[i] = by;
	return (ptr);
}

/**
 * str_free - frees a string of strings
 * @sos: string of strings
 */
void str_free(char **sos)
{
	char **a = sos;

	if (!sos)
		return;
	while (*sos)
		free(*sos++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @oldsz: byte size of previous block
 * @newsz: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
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
