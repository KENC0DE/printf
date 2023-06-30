#include "main.h"

/**
 * rec_long_hexal - use recursion for address.
 * @num: passed number.
 * @hex: hexal
 * Return: bytes written.
*/
int rec_long_hexal(unsigned long int num, char *hex)
{
	int rem, bytes = 0;
	char c;

	if (num / 16 == 0)
	{
		c = '0' + num;
		if (num > 9)
		{
			unsigned int j, k = 0;

			for (j = 10; j <= 15; j++, k++)
			{
				if (num == j)
					buffit(hex[k]);
			}
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
	bytes += rec_long_hexal(num, hex);
	bytes += buffit(c);
	return (bytes);
}

/**
 * long_hexal - change passed num to hexadecimal
 * @num: unsigned int passed.
 * Return: bytes written.
*/
int long_hexal(unsigned long int num)
{
	int bytes = 0;
	char hex[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	bytes = rec_long_hexal(num, hex);

	return (bytes);
}

/**
 * print_addr - print address.
 * @pull: accuried address
 * Return: written bytes.
*/
int print_addr(va_list pull)
{
	unsigned long int num;
	int bytes = 0, i;

	num = va_arg(pull, unsigned long int);
	if (num <= 0)
	{
		char *str = "(nil)";

		for (i = 0; str[i]; i++)
			bytes += buffit(str[i]);
		return (bytes);
	}

	buffit('0');
	buffit('x');
	bytes += 2;
	bytes += long_hexal(num);

	return (bytes);
}
