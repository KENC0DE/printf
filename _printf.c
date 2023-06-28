#include "main.h"

/**
 * _printf - do the same as printf
 * @format: specified format.
 * Return: byes writen.
*/
int _printf(const char *format, ...)
{
	int bytes;
	va_list pull;

	if (format == NULL)
		return (-1);

	bytes = _strlen(format);
	if (bytes <= 0)
		return (0);

	va_start(pull, format);
	bytes = ext_func(format, pull);

	buffit(-1);
	va_end(pull);
	return (bytes);
}
