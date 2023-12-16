#include "shell.h"
/**
 * _strlength - strlenth
 * @achstr: str
 * Return: intlen
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
 * _str_comp - comparestr
 * @fs: fstr
 * @ss: sstr
 *
 * Return: neg or pos or zeo
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
 * starts_with - hastck
 * @ssearch: strsearch
 * @ssfind: sstr
 * Return: nexchaadr
 */
char *starts_with(const char *ssearch, const char *ssfind)
{
	while (*ssfind)
		if (*ssfind++ != *ssearch++)
			return (NULL);
	return ((char *)ssearch);
}

/**
 * _str_cat - sttwoconca
 * @desti: bufdest
 * @sbuf: bufsor
 *
 * Return: destbufadr
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
