 #include "shell.h"

/**
 *_eputs - prints an input string to the stderr
 * @str: String to be printed out
 *
 * Return: 0
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to  the stderr
 * @cha: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char cha)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (cha != BUF_FLUSH)
		buffer[i++] = cha;
	return (1);
}

/**
 * _putfd - allows you to specify fd to which the character c will be written.
 * @cha: The character to print
 * @fd: The filedescriptor to write to.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char cha, int fd)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (cha != BUF_FLUSH)
		buffer[i++] = cha;
	return (1);
}

/**
 *_putsfd - prints an entire string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
