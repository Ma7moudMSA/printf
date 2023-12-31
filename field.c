#include "main.h"

/**
* get_precision - fn name
* @str: input str
* @par: typedef
* @print: variadic fn
*
* Return: char
*/

char *get_precision(char *str, paramst *par, va_list print)

{
	int num = 0, x = 0;

	if (x == 0)
		x = 1;
	if (*str != '.')
		return (str);
	str++;
	if (*str == '*')
	{
		num = va_arg(print, int);
		str++;
		x++;
	}
	else
	{
		while (_isdigit(*str))
			num = (10 * num) + (*str++ - '0');
	}
	par->precision = num;
	return (str);
}
