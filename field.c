#include "main.h"

/**
* get_percision - fn name
* @str: input str
* @par: typedef
* @print: variadic fn
*
* Return: char
*/

char *get_percision(char *str, paramst *par, va_list print)
{
	int num = 0;

	if (*str != '.')
		return (str);
	str++;
	if (*str == '*')
	{
		num = va_arg(print, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			sum = (10 * sum) + (*str++ - '0');
	}
	par->percision = sum;
	return (str);
}
