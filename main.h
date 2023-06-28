#ifndef PRTF_HEADER
#define PRTF_HEADER

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct functions - function data.
 * @c: specifier.
 * @func: function.
*/
typedef struct functions
{
	char c;
	int (*func)(va_list);
} func_t;

/* Excution preparation functions */
int _printf(const char *format, ...);
int ext_func(const char *format, va_list);
int chose_func(const char *format, va_list, int *idx);

/* Format handling functions */
int print_char(va_list);
int print_str(va_list);
int print_int(va_list);
int print_binary(va_list);
int rot_13(va_list);
int print_rev(va_list);
int hex_nonPrint(va_list);
int print_Uint(va_list);
int print_octal(va_list);
int print_hexlow(va_list);
int print_hexUP(va_list);
int print_addr(va_list);

/* Extra funcitions */
int _strlen(const char *str);
int _strlenv2(char *str);
int buffit(char c);
int rec_hexal(unsigned int num, char *hex);

#endif
