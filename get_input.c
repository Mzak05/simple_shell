#include "shell.h"
/**
 * input_buf - buffers chained commands
 * @infffo: parameter struct
 * @bufbuf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_type *infffo, char **bufbuf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) 
	{
	
		free(*bufbuf);
		*bufbuf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(bufbuf, &len_p, stdin);
#else
		r = _getline(infffo, bufbuf, &len_p);
#endif
		if (r > 0)
		{
			if ((*bufbuf)[r - 1] == '\n')
			{
				(*bufbuf)[r - 1] = '\0'; 
				r--;
			}
			infffo->linecount_flag = 1;
			remove_comments(*bufbuf);
			build_history_l(infffo, *bufbuf, infffo->histcount++);
			
			{
				*len = r;
				infffo->cmd_buf = bufbuf;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @infffo: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_type *infffo)
{
	static char *bufbuf; 
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(infffo->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(infffo, &bufbuf, &len);
	if (r == -1) 
		return (-1);
	if (len)	
	{
		j = i; 
		p = bufbuf + i; 
		check_chain(infffo, bufbuf, &j, i, len);
		while (j < len) 
		{
			if (is_chain_del(infffo, bufbuf, &j))
				break;
			j++;
		}

		i = j + 1; 
		if (i >= len) 
		{
			i = len = 0; 
			infffo->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; 
		return (_strlength(p)); 
	}

	*buf_p = bufbuf; 
	return (r); 
}

/**
 * read_buf - reads a buffer
 * @infffo: parameter struct
 * @bufbuf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_type *infffo, char *bufbuf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(infffo->readfd, bufbuf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @infffo: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_type *infffo, char **ptr, size_t *length)
{
	static char bufbuf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(infffo, bufbuf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _str_chr(bufbuf + i, '\n');
	k = c ? 1 + (unsigned int)(c - bufbuf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) 
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, bufbuf + i, k - i);
	else
		_strn_copy(new_p, bufbuf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
