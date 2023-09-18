#include "main.h"

/**
 * print_d - prints an integer
 * @args: list of arguments
 * @count: a pointer to the count of characters printed
 *
 * Return: Nothing.
 */
void print_d(va_list args, int *count)
{
	int value = va_arg(args, int);

	if (value < 0)
	{
		putchar('-');
		(*count)++;
		value = -value;
	}
	if (value / 10)
		print_d(value / 10);
	putchar(value % 10 + '0');
	(*count)++;
}

/**
 * print_i - prints an integer
 * @args: list of arguments
 *
 * Return: Nothing.
 */
void print_i(va_list args)
{
	print_d(args);
}

