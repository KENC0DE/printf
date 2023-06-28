#include "main.h"

/**
 * rec_binary - prints binary number with recursion.
 * @num: number to be converted.
 * Return: bytes written.
*/
int rec_binary(unsigned int num)
{
	int rem, bytes = 0;
	char c;

	if (num / 2 == 0)
	{
		c = '0' + num;
		buffit(c);
		return (1);
	}

	rem = num % 2;
	num /= 2;
	c = '0' + rem;
	bytes += rec_binary(num);
	bytes += buffit(c);
	return (bytes);
}

/**
 * print_binary - prints binary form of a passed number.
 * @pull: accured number.
 * Return: bytes written.
*/
int print_binary(va_list pull)
{
	unsigned int num;
	int bytes = 0;

	num = va_arg(pull, unsigned int);

	bytes += rec_binary(num);

	return (bytes);
}

/**
 * rot_it - rotate string passed by 13.
 * @str: string.
 * @rot: rotated string storage.
 * @l: length of the string.
 * Return: nothing.
*/
void rot_it(char *rot, char *str, int l)
{
	int i;
	char c;

	for (i = 0; str[i]; i++)
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
		{
			if (c + 13 > 'z')
			{
				c = 'z' - c;
				c = 13 - c;
				rot[i] = 'a' + c - 1;
			}
			else
				rot[i] = c + 13;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c + 13 > 'Z')
			{
				c = 'Z' - c;
				c = 13 - c;
				rot[i] = 'A' + c - 1;
			}
			else
				rot[i] = c + 13;
		}
		else
			rot[i] = c;
	}
	rot[l] = '\0';
	for (i = 0; rot[i]; i++)
		buffit(rot[i]);
}

/**
 * rot_13 - print by 13 rotated of the char.
 * @pull: accure string.
 * Return: bytes written.
*/
int rot_13(va_list pull)
{
	char *str, *rot;
	int l;

	str = va_arg(pull, char *);
	if (str == NULL)
		str = "(null)";

	l = _strlenv2(str);
	rot = malloc(sizeof(char) * (l + 1));
	if (rot == NULL)
		return (-1);

	rot_it(rot, str, l);

	free(rot);
	return (l);
}
