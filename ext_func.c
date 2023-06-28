#include "main.h"

/**
 * ext_func - excute the right functions.
 * @format: specified format.
 * @pull: arguments.
 * Return: bytes written.
*/
int ext_func(const char *format, va_list pull)
{
	int bytes, idx, err;

	bytes = 0;
	for (idx = 0; format[idx] != 0; idx++)
	{
		if (format[idx] == '%')
		{
			err = chose_func(format, pull, &idx);
			if (err == -1)
				return (-1);

			bytes += err;
			continue;
		}

		buffit(format[idx]);
		bytes++;
	}

	return (bytes);
}

/**
 * chose_func - slect appropriate function to excute.
 * @format: specifed print format.
 * @pull: argument pull.
 * @idx: current index.
 * Return: bytes written.
*/
int chose_func(const char *format, va_list pull, int *idx)
{
	int bytes, rn;
	char c;
	func_t func[] = {
		{'c', print_char}, {'s', print_str},
		{'d', print_int}, {'i', print_int},
		{'b', print_binary}, {'R', rot_13},
		{'r', print_rev}, {'S', hex_nonPrint},
		{'u', print_Uint}, {'o', print_octal},
		{'x', print_hexlow}, {'X', print_hexUP},
		{'p', print_addr},
		{'\0', NULL}
	};

	*idx = *idx + 1;
	if (format[*idx] == '\0')
		return (-1);

	if (format[*idx] == '%')
	{
		buffit(format[*idx]);
		return (1);
	}

	for (rn = 0; func[rn].c; rn++)
	{
		if (func[rn].c == format[*idx])
		{
			bytes = func[rn].func(pull);
			return (bytes);
		}
	}
	c = '%';
	buffit(c);
	buffit(format[*idx]);
	return (2);
}
