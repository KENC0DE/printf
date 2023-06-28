#include "main.h"

/**
 * print_char - prints character.
 * @pull: aquired char.
 * Return: bytes written.
*/
int print_char(va_list pull)
{
	char c = va_arg(pull, int);

	buffit(c);
	return (1);
}

/**
 * print_str - prints stirng.
 * @pull: aquired stirng.
 * Return: bytes written.
*/
int print_str(va_list pull)
{
	char *str;
	int l, i;

	str = va_arg(pull, char *);
	if (str == NULL)
		str = "(null)";

	l = _strlenv2(str);
	for (i = 0; str[i]; i++)
		buffit(str[i]);

	return (l);
}

/**
 * int_rec - print each digit with recursion.
 * @num: number to be printed.
 * @flag: min check.
 * Return: bytes written.
*/
int int_rec(int num, int flag)
{
	char c;
	int bytes = 0, rem;

	if (num < 10)
	{
		c = '0' + num;
		buffit(c);
		return (1);
	}
	rem = num % 10;
	num /= 10;

	if (flag == -1)
	{
		rem++;
		flag = 1;
	}

	c = '0' + rem;
	bytes += int_rec(num, flag);
	buffit(c);
	bytes++;
	return (bytes);
}

/**
 * print_int - prints integer.
 * @pull: accured number.
 * Return: bytes written.
*/
int print_int(va_list pull)
{
	int num, bytes = 0, flag = 1;

	num = va_arg(pull, int);
	if (num < 0)
	{
		char c = '-';

		num = -(num);
		buffit(c);
		bytes++;
	}
	if (num == -2147483648)
	{
		num++;
		num = -(num);
		flag = -1;
	}
	bytes += int_rec(num, flag);

	return (bytes);
}
