#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 * @count: Pointer to the count of characters
 */
void print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	_putchar(c);
	(*count)++;
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @count: Pointer to the count of characters
 */
void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	for (; *s; s++)
	{
		_putchar(*s);
		(*count)++;
	}
}

/**
 * print_percent - Prints a percent character
 * @count: Pointer to the count of characters
 */
void print_percent(int *count)
{
	_putchar('%');
	(*count)++;
}

/**
 * _printf - printf function
 * @format: format.
 *
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *traverse;

	va_start(args, format);

	for (traverse = format; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%' && *traverse != '\0')
		{
			_putchar(*traverse);
			traverse++;
			count++;
		}

		if (*traverse == '\0')
			break;

		switch (*++traverse)
		{
		case 'c':
			print_char(args, &count);
			break;
		case 's':
			print_string(args, &count);
			break;
		case '%':
			print_percent(&count);
			break;
		default:
			break;
		}
	}

	va_end(args);
	return (count);
}
