#include "shell.h"

/**
* is_cmd - function to determine if a file is an executable command
*
* contributor - MUHAMMAD ABDULRAHMAN (mabdul.am25@gmail.com)
* DELPHINE UZOETO (delphineamaka@gmail.com)
*
* @info: the info struct
* @path: path link to the file
*
* Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
* dup_chars - function to get duplicate characters
* @pathstring: the PATH string
* @start_index: starting indexing value/index
* @stop_index: stop indexing value/index
*
* Return: return pointer to new buffer
*/
char *dup_chars(char *pathstring, int start_index, int stop_index)
{
static char buf[1024];
int i = 0, k = 0;

for (k = 0, i = start_index; i < stop_index; i++)
if (pathstring[i] != ':')
buf[k++] = pathstring[i];
buf[k] = 0;
return (buf);
}

/**
* find_path - finds this cmd in the PATH string
* @info: the info struct
* @pathstring: the PATH string
* @cmd: the cmd to find
*
* Return: full path of cmd if found or NULL
*/
char *find_path(info_t *info, char *pathstring, char *cmd)
{
int i = 0;
int curr_pos = 0;
char *path;

if (!pathstring)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstring[i] || pathstring[i] == ':')
{
path = dup_chars(pathstring, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstring[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}
