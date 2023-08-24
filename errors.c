#include "shell.h"

/**
 * _eputs - output input string value
 * @str: the string val
 *
 * Return: Nothing
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
* _eputchar - function writes character ch to stderr
* @ch: character to print
*
* Return: On success, return 1.
* On error, return -1 and set errno appropriately.
*/
int _eputchar(char ch)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (ch != BUF_FLUSH)
buf[i++] = ch;
return (1);
}

/**
* _putfd - function that writes the ch to a given fd
* @ch: The character
* @fd: The file descriptor to write to
*
* Return: On success, return 1.
* On error, return -1 and set errno appropriately.
*/
int _putfd(char ch, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (ch != BUF_FLUSH)
buf[i++] = ch;
return (1);
}

/**
* _putsfd - function that print an input
* @str: string
* @fd: the file descriptor to write to
*
* Return: number of chars
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
