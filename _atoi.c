#include "shell.h"

/**
* interactive - returns true if shell is interactive mode
* @info: is the struct passinfo address
*
* Return: 1 if interactive mode, 0 otherwise
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
* is_delimiter - this checks if the inputed character is a delimeter
* @c: is the char to be checked
* @delimeter: is the delimeter string
* Return: 1 if true, 0 if false
*/
int is_delimiter(char c, char *delimeter)
{
while (*delimeter)
if (*delimeter++ == c)
return (1);
return (0);
}


/**
* _isalpha - this checks for any alphabetic character input
* @c: The character to input
* Return: 1 if c is alphabetic, 0 otherwise
*/


int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}


/**
* _atoi - converts a string value to an integer value
* @str_val: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/


int _atoi(char *str_val)
{
int i;
int sign = 1;
int flag = 0;
int output;
unsigned int result = 0;


for (i = 0; str_val[i] != '\0' && flag != 2; i++)
{
if (str_val[i] == '-')
sign *= -1;


if (str_val[i] >= '0' && str_val[i] <= '9')
{
flag = 1;
result *= 10;
result += (str_val[i] - '0');
}
else if (flag == 1)
flag = 2;
}


if (sign == -1)
output = -result;
else
output = result;


return (output);
}
