#include "shell.h"

/**
 * _erratoi - func that convert string to integer
 * @s: string to convert
 * Return: 0 if no numb exist in string, otherwise numb
 *        -1 on error
 */
int _erratoi(char *s)
{
int val = 0;
unsigned long int result = 0;

if (*s == '+')
s++;
for (val = 0;  s[val] != '\0'; val++)
{
if (s[val] >= '0' && s[val] <= '9')
{
result *= 10;
result += (s[val] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
* print_error - func that print error message
*
* @info: return struct info
* @estr: string that contains specific error type
* Return: return 0 if numbers NOT in string, else converted number
*        else -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
* print_d - function that print a decimal to the specified fd
* @input: input value
* @filedescriptor: file descriptor to write to
*
* Return: number of characters printed
*/
int print_d(int input, int filedescriptor)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;

if (filedescriptor == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;

return (count);
}

/**
* convert_number - Converts number to a string.
* @num: value
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long un_ln = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
un_ln = -num;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do        {
*--ptr = array[un_ln % base];
un_ln /= base;
} while (un_ln != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
* remove_comments - function removes comment
*                   by replacing the first instance of '#' with '\0'.
* @buf: string address to modify
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
}
