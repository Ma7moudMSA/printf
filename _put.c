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

int _putchar(char c)
{
	return (write(1, &c, 1));
}
