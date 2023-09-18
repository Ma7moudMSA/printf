#include "main.h"

/**
* get_spec - finds the format
* @s: fomar string
*
* Return: number of bytes
*/

int (*get_spec(char *s))(va_list print, paramst * par)
{
	sf_t spec[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (spec[i].specifier)
	{
		if (*s == spec[i].specifier[0])
		{
			return (spec[i].function);
		}
		i++;
	}
	return (NULL);
}

/**
* get_print_function - fn name
* @s: input
* @print: we malo
* @par: my struct
*
* Return: int
*/


int get_print_function(char *s, va_list print, paramst *par)
{

	int (*function)(va_list, paramst *) = get_spec(s);

	if (function)
		return (function(print, par));
	return (0);
}

/**
* get_flag - fn name
* @s: input ptr
* @par: your paramter
*
* Return: valid
*/

int get_flag(char *s, paramst *par)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = par->flag = 1;
			break;
		case ' ':
			i = par->space = 1;
			break;
		case '#':
			i = par->hashtag = 1;
			break;
		case '-':
			i = par->minus = 1;
			break;
		case '0':
			i = par->zero = 1;
			break;
	}
	return (i);
}

/**
* get_modifier - find modifer func
*
