#include "main.h"

/**
* _puts - print all string with newline
* @str: input
*
* Return: number of bytes
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
* _putchar - fn name
* @c: input char
*
* Return: on succes 1
* On error -1
*/

int _putchar(int c)
{
	static int p;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || p >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}
