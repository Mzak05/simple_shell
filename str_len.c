#include "shell.h"
/**
 * _strlength - returns the length of a string
 * @achstr: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlength(char *achstr)
{
	int i = 0;

	if (!achstr)
		return (0);

	while (*achstr++)
		i++;
	return (i);
}

/**
 * _str_comp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _str_comp(char *fs, char *ss)
{
	while (*fs && *ss)
	{
		if (*fs != *ss)
			return (*fs - *ss);
		fs++;
		ss++;
	}
	if (*fs == *ss)
		return (0);
	else
		return (*fs < *ss ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @ssearch: string to search
 * @ssfind: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *ssearch, const char *ssfind)
{
	while (*ssfind)
		if (*ssfind++ != *ssearch++)
			return (NULL);
	return ((char *)ssearch);
}

/**
 * _str_cat - concatenates two strings
 * @desti: the destination buffer
 * @sbuf: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_str_cat(char *desti, char *sbuf)
{
	char *ret = desti;

	while (*desti)
		desti++;
	while (*sbuf)
		*desti++ = *sbuf++;
	*desti = *sbuf;
	return (ret);
}
