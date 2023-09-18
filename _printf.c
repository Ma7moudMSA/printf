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

	va_start(print, format);

	int s = 0;
	int check;
	char *str, begin;

	paramst par = params_init;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (str = format; *str; str++)
	{
		init_par(&par, print);
		if (*str != '%')
		{
			s += _putchar(*str);
			continue;
		}
		begin = str;
		str++;
		while (get_flag(str, &par))
		(
			str++;
		)
		str = get_width(str, &par, print);
		str = get_precision(str, &par, print);
		if (get_modifier(str, &par))
			str++;
		if (!get_specifier(str))
		{
			check = par.l || par.h ? str - 1 : 0;
			s += print_from_to(begin, str, check);
		}
		else
			s += get_print_func(str, print, &par);
	}
	_putchar(BUF_FLUSH);
	va_end(print);
	return (s);
}
