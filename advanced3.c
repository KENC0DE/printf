#include "main.h"

/**
 * rec_hexal - print them in recursion
 * @num: number to be converted.
 * @hex: letters
 * Return: bytes written.
*/
int rec_hexal(unsigned int num, char *hex)
{
	int rem, bytes = 0;
	char c;

	if (num / 16 == 0)
	{
		c = '0' + num;
		if (num > 9)
		{
			unsigned int j, k = 0;

			buffit('0');
			for (j = 10; j <= 15; j++, k++)
			{
				if (num == j)
					buffit(hex[k]);
			}
			return (2);
		}
		else
			buffit('0' + num);

		return (1);
	}
	rem = num % 16;
	if (rem > 9)
	{
		int j2, k2 = 0;

		for (j2 = 10; j2 <= 15; j2++, k2++)
		{
			if (rem == j2)
				c = hex[k2];
		}
	}
	else
		c = '0' + rem;
	num /= 16;
	bytes += rec_hexal(num, hex);
	bytes += buffit(c);
	return (bytes);
}

/**
 * hexal - change passed num to hexadecimal
 * @num: unsigned int passed.
 * @flag: upper or lower.
 * Return: bytes written.
*/
int hexal(unsigned int num, int flag)
{
	int i, bytes = 0;
	char hex[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	if (flag == 1)
		for (i = 0; hex[i]; i++)
			hex[i] += 32;

	bytes = rec_hexal(num, hex);

	return (bytes);
}

/**
 * print_hexUP - prints octal form of a passed number.
 * @pull: accured number.
 * Return: bytes written.
*/
int print_hexUP(va_list pull)
{
	unsigned int num;
	int bytes = 0;

	num = va_arg(pull, unsigned int);

	bytes += hexal(num, 0);

	return (bytes);
}

/**
 * print_hexlow - prints octal form of a passed number.
 * @pull: accured number.
 * Return: bytes written.
*/
int print_hexlow(va_list pull)
{
	unsigned int num;
	int bytes = 0;

	num = va_arg(pull, unsigned int);

	bytes += hexal(num, 1);

	return (bytes);
}
