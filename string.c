#include "shell.h"

/**
* _strlen - return string length
* @s: parameter whose length is to be checked
*
* Return: integer length of string
*/
int _strlen(char *s)
{
int i = 0;

if (!s)
return (0);

while (*s++)
i++;
return (i);
}

/**
* _strcmp - function to perform lexical comparison.
* @stg1: first data(strang)
* @stg2: second data
*
* Return: if stg1 < stg2, return negative, if stg1 > stg2, return positive
*         and zero if stg1 == stg2
*/
int _strcmp(char *stg1, char *stg2)
{
while (*stg1 && *stg2)
{
if (*stg1 != *stg2)
return (*stg1 - *stg2);
stg1++;
stg2++;
}
if (*stg1 == *stg2)
return (0);
else
return (*stg1 < *stg2 ? -1 : 1);
}

/**
* starts_with - Verifies if needle begins with haystack
* @haystack: string to search for
* @needle: the substring to find
*
* Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - function to concatenate two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
