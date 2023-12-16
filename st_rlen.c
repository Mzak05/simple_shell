#include "shell.h"
int _strlength(char *achstr)
{
	int i = 0;

	if (!achstr)
		return (0);

	while (*achstr++)
		i++;
	return (i);
}
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

char *starts_with(const char *ssearch, const char *ssfind)
{
	while (*ssfind)
		if (*ssfind++ != *ssearch++)
			return (NULL);
	return ((char *)ssearch);
}

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
