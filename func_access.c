#include "main.h"

/**
 * _strlen - get string length.
 * @str: string.
 * Return: length of string.
*/
int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _strlenv2 - get string length.
 * @str: string.
 * Return: length of string.
*/
int _strlenv2(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
