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
* _putchar - writes the character c to stdout
* @c: The character to print *
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(int c)
{
	static int p, check;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || p >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
		check++;
	if (c == 1)
		check = 0;
	return (1);
}
