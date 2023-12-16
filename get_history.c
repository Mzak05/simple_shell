#include "shell.h"
char *get_history_f(info_type *infffo)
{
	char *bufbuf, *dir;

	dir = _get_env(infffo, "HOME=");
	if (!dir)
		return (NULL);
	bufbuf = malloc(sizeof(char) * (_strlength(dir) + _strlength(HIST_FILE) + 2));
	if (!bufbuf)
		return (NULL);
	bufbuf[0] = 0;
	_str_copy(bufbuf, dir);
	_str_cat(bufbuf, "/");
	_str_cat(bufbuf, HIST_FILE);
	return (bufbuf);
}

int write_history(info_type *infffo)
{
	ssize_t fd;
	char *filename = get_history_f(infffo);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = infffo->history; node; node = node->next)
	{
		_puts_fd(node->str, fd);
		_put_fd('\n', fd);
	}
	_put_fd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

int read_hist(info_type *infffo)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *bufbuf = NULL, *filename = get_history_f(infffo);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bufbuf = malloc(sizeof(char) * (fsize + 1));
	if (!bufbuf)
		return (0);
	rdlen = read(fd, bufbuf, fsize);
	bufbuf[fsize] = 0;
	if (rdlen <= 0)
		return (free(bufbuf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (bufbuf[i] == '\n')
		{
			bufbuf[i] = 0;
			build_history_l(infffo, bufbuf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_l(infffo, bufbuf + last, linecount++);
	free(bufbuf);
	infffo->histcount = linecount;
	while (infffo->histcount-- >= HIST_MAX)
		delete_node(&(infffo->history), 0);
	renumber_history(infffo);
	return (infffo->histcount);
}

int build_history_l(info_type *infffo, char *buf, int linecount)
{
	list_t *node = NULL;

	if (infffo->history)
		node = infffo->history;
	add_node_end(&node, buf, linecount);

	if (!infffo->history)
		infffo->history = node;
	return (0);
}

int renumber_history(info_type *infffo)
{
	list_t *node = infffo->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (infffo->histcount = i);
}
