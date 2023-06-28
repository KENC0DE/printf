#include "main.h"

/**
 * print_rev - print string in reverse
 * @pull: accured string.
 * Return: bytes written.
*/
int print_rev(va_list pull)
{
	int i = 0, l = 0;
	char *str = va_arg(pull, char *);

	if (str == NULL)
		str = "(null)";

	l = _strlenv2(str);
	for (i = l - 1; i >= 0; i--)
		buffit(str[i]);/* write(1, &str[i], 1);*/

	return (l);
}

/**
 * hex_nonPrint - change non-printable to hexadecimal.
 * @pull: accured string.
 * Return: written bytes.
*/
int hex_nonPrint(va_list pull)
{
	char *str;
	char hexS[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int i, hxd = 0;

	str = va_arg(pull, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] > '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			hxd += 3;
			buffit(92);
			buffit('x');
			buffit('0');
			hxd += rec_hexal(str[i], hexS);
		}
		else
			hxd += buffit(str[i]);
	}

	return (hxd);
}
