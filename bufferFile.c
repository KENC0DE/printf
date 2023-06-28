#include "main.h"

/**
 * buffit - temorary storage for char store to write at once.
 * @c: passed character.
 * Return: 1 on successe -1 if falied.
*/
int buffit(char c)
{
	static char buff[1024];
	static int sp;

	if (c == -1 || sp == 1024)
	{
		write(1, buff, sp);
		sp = 0;
	}

	if (c != -1)
	{
		buff[sp] = c;
		sp++;
	}
	return (1);
}
