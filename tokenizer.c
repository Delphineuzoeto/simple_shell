#include "shell.h"

/**
* **strtow - Divides a string into separate words.
*            Repeated delimiters are not counted as separate words.
* @str: string input
* @delm: string delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *delm)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!delm)
delm = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delimiter(str[i], delm) && (is_delimiter(str[i + 1],
delm) || !str[i + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delimiter(str[i], delm))
i++;
k = 0;
while (!is_delimiter(str[i + k], delm) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
* **strtow2 - function split string into words
* @str: string input
* @delm: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char delm)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != delm && str[i + 1] == delm) ||
(str[i] != delm && !str[i + 1]) || str[i + 1] == delm)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == delm && str[i] != delm)
i++;
k = 0;
while (str[i + k] != delm && str[i + k] && str[i + k] != delm)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}
