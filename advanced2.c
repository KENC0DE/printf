#include "main.h"

/**
 * rec_it - print them in recursion
 * @num: number to be converted.
 * @div: divisor.
 * Return: bytes written.
*/
int rec_it(unsigned int num, unsigned int div)
{
	int rem, bytes = 0;
	char c;

	if (num / div == 0)
	{
		c = '0' + num;
		buffit(c);
		return (1);
	}

	rem = num % div;
	num /= div;
	c = '0' + rem;
	bytes += rec_it(num, div);
	bytes += buffit(c);
	return (bytes);
}

/**
 * print_Uint - prints unsigned int
 * @pull: accured unsigned int
 * Return: written bytes.
*/
int print_Uint(va_list pull)
{
	unsigned int num;
	int bytes = 0;

	num = va_arg(pull, unsigned int);

	bytes += rec_it(num, 10);

	return (bytes);
}

/**
 * print_octal - prints octal form of a passed number.
 * @pull: accured number.
 * Return: bytes written.
*/
int print_octal(va_list pull)
{
	unsigned int num;
	int bytes = 0;

	num = va_arg(pull, unsigned int);

	bytes += rec_it(num, 8);

	return (bytes);
}
