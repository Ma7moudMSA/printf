#include "main.h"

/**
* _printf - fn name
* @format: the string input
*
* Return: the number of bytes
*/
int _printf(const char *format, ...)
{
	va_list print;
	int counter = 0;
	char *str, *begin;
	paramst par = params_init;

	va_start(print, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (str = (char *)format; *str; str++)
	{
		init_par(&par, print);
		if (*str != '%')
		{
			counter += _putchar(*str);
			continue;
		}
		begin = str;
		str++;
		while (get_flag(str, &par))
		{
			str++;
		}
		str = get_width(str, &par, print);
		str = get_precision(str, &par, print);
		if (get_modifier(str, &par))
			str++;
		if (!get_spec(str))
		{
			counter += print_from_to(begin, str, par.l || par.h ? str - 1 : 0);
		}
		else
			counter += get_print_function(str, print, &par);
	}
	_putchar(BUF_FLUSH);
	va_end(print);
	return (counter);
}
