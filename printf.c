#include "main.h"

/**
* _printf - fn name
* @format: input
*
* Return: int value
*/

int _printf(const char *format, ...)
{
	int i = 0;

	char result = '%';

	char *str;

	va_list print;
	va_start(print, format);

	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] == result)
			{
				switch (format[i + 1])
				{
					case 'c':
						putchar(va_arg(print, int));
						break;
					case '%':
						putchar(va_arg(print, int));
						break;
					case 's':
						str = va_arg(print, char *);
						while (*str)
						{
							putchar(*str);
							str++;
						}
						break;
				}
			i++;
			}
			else
			{
				putchar(format[i]);
				i++;
			}
		}
	}
	va_end(print);
	return (i);
}
