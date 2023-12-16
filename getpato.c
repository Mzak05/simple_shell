#include "shell.h"
int is_command(info_type *infffo, char *path)
{
	struct stat st;

	(void)infffo;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & __S_IFREG)
	{
		return (1);
	}
	return (0);
}

char *dupli_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

char *find_path(info_type *infffo, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlength(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_command(infffo, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dupli_chars(pathstr, curr_pos, i);
			if (!*path)
				_str_cat(path, cmd);
			else
			{
				_str_cat(path, "/");
				_str_cat(path, cmd);
			}
			if (is_command(infffo, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

