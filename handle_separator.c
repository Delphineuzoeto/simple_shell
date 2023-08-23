#include "shell.h"

/**
 * input_buffer - Buffers chained commands
 * @info: Parameter struct
 * @buffer: Address of the buffer
 * @lenght: Address of the length variable
 *
 * Return: Number of bytes read
 */
ssize_t input_buf(info_t *info, char **buffer, size_t *lenght)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*lenght) /* If buffer is empty, read and process input */
	{
		/* bfree((void **)info->cmd_buf); */
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);

#if USE_GETLINE
		r = getline(buffer, &len_p, stdin);
#else
		r = _getline(info, buffer, &len_p);
#endif

		if (r > 0)
		{
			if ((*buffer)[r - 1] == '\n')
			{
				(*buffer)[r - 1] = '\0'; /* This removes trailing new line */
				r--;
			}

			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);

			/* Help to know a command chain using _strchr(*buffer, ';') */
			{
				*lenght = r;
				info->cmd_buf = buffer;
			}
		}
	}

	return (r);
}

/**
 * get_input - Gets a line without including the newline character
 * @info: Parameter struct
 *
 * Return: Number of bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buffer; /* Buffer for ';' command chain */
	static size_t i, j, lenght;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buffer, &lenght);

	if (r == -1) /* EOF */
		return (-1);

	if (lenght)
	{
		j = i; /* Initialize new iterator to current buffer position */
		p = buffer + i; /* Gets a pointer for return */

		check_chain(info, buffer, &j, i, lenght);

		while (j < lenght) /* Iterates to semicolon or terminates */
		{
			if (is_chain(info, buffer, &j))
				break;
			j++;
		}

		i = j + 1; /* Increment past nulled semicolon */
		if (i >= lenght) /* Reached end of buffer? */
		{
			i = lenght = 0; /* Reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* Pass back pointer to current command position */
		return (_strlen(p)); /* Return length of current command */
	}

	*buf_p = buffer; /* Not a chain, pass back buffer from _getline() */
	return (r); /* Return length of buffer from _getline() */
}

/**
 * read_buffer - Reads a buffer
 * @info: Parameter struct
 * @buffer: Buffer
 * @i: Size
 *
 * Return: Bytes read
 */
ssize_t read_buf(info_t *info, char *buffer, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);

	r = read(info->readfd, buffer, READ_BUF_SIZE);

	if (r >= 0)
		*i = r;

	return (r);
}

/**
 * _getline - Gets the next line of input from STDIN
 * @info: Parameter struct
 * @ptr: Address of pointer to buffer, preallocated or NULL
 * @len: Size of preallocated ptr buffer if not NULL
 *
 * Return: Length of input
 */
int _getline(info_t *info, char **ptr, size_t *len)
{
	static char buffer[READ_BUF_SIZE];
	static size_t i, lenght;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;

	if (p && len)
		s = *len;

	if (i == lenght)
		i = lenght = 0;

	r = read_buf(info, buffer, &lenght);

	if (r == -1 || (r == 0 && lenght == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : lenght;

	new_p = _realloc(p, s, s ? s + k : k + 1);

	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buffer + i, k - i);
	else
		_strncpy(new_p, buffer + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (len)
		*len = s;

	*ptr = p;
	return (s);
}

/**
 * sigintHandler - Blocks Ctrl-C command
 * @sig_num: The number of signal
 *
 * Return: Void
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

