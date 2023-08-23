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

<<<<<<< HEAD:errors1.c
/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
=======
if (!str)
return;
while (str[i] != '\0')
>>>>>>> a695f1c0506b1077ae08d382f6a339acffaa3de2:errors.c
{
_eputchar(str[i]);
i++;
}
}

/**
<<<<<<< HEAD:errors1.c
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
=======
* _eputchar - function writes character ch to stderr
* @ch: character to print
*
* Return: On success, return 1.
* On error, return -1 and set errno appropriately.
*/
int _eputchar(char ch)
>>>>>>> a695f1c0506b1077ae08d382f6a339acffaa3de2:errors.c
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (ch != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
<<<<<<< HEAD:errors1.c
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
=======
* _putfd - function that writes the ch to a given fd
* @ch: The character
* @fd: The file descriptor to write to
*
* Return: On success, return 1.
* On error, return -1 and set errno appropriately.
*/
int _putfd(char ch, int fd)
>>>>>>> a695f1c0506b1077ae08d382f6a339acffaa3de2:errors.c
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
<<<<<<< HEAD:errors1.c
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
=======
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
>>>>>>> a695f1c0506b1077ae08d382f6a339acffaa3de2:errors.c
}
