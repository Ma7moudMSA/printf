#include "main.h"

/**
* _isdigit - fn name
* @c: input number
*
* Return: 1 if digit
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
	return (0);
}

/**
* _strlen - fn name
* @s: get length of string s
*
* Return: length of string
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
* print_number - fn name
* @str: ptr name
* @par: struct
*
* Return: check
*/

int print_number(char *str, paramst *par)
{
	unsigned int i = _strlen(str);
	int n = (!par->unsign && *str == '-');

	if (!par->precision && *str == '0' && !str[1])
		str = "";
	if (n)
	{
		str++;
		i--;
	}
	if (par->precision != UINT_MAX)
		while (i++ < par->precision)
			*--str = '0';
	if (n)
		*--str = '-';
	if (!par->minus)
		return (print_number_right_shift(str, par));
	else
		return (print_number_left_shift(str, par));
}

/**
* print_number_right_shift - eh ya3am fn name
* @str: string ptr
* @par: my struct
*
* Return: interger
*/

int print_number_right_shift(char *str, paramst *par)
{
	unsigned int n = 0, ne, n2, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero && !par->minus)
		pad_char = '0';
	ne = n2 = (!par->unsign && *str == '-');
	if (ne && i < par->width && pad_char == '0' && !par->minus)
		str++;
	else
		ne = 0;
	if ((par->plus && !n2) ||
		(!par->plus && par->space && !n2))
		i++;
	if (ne && pad_char == '0')
		n += _putchar('-');
	if (par->plus && !n2 && pad_char == '0' && !par->unsign)
		n += _putchar('+');
	else if (!par->plus && par->space && !n2 &&
		!par->unsign && par->zero)
		n += _putchar (' ');
	while (i++ < par->width)
		n += _putchar(pad_char);
	if (ne && pad_char == ' ')
		n += _putchar('-');
	if (par->plus && !n2 && pad_char == ' ' && !par->unsign)
		n += _putchar('+');
	else if (!par->plus && par->space && !n2 &&
		!par->unsign && !par->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
* print_number_left_shift - eh ya3am
* @str: string ptr
* @par: my struct
*
* Return: interger
*/

int print_number_left_shift(char *str, paramst *par)
{
	unsigned int n = 0, ne, n2, i = _strlen(str);
	char pad_char = ' ';

	if (par->zero && !par->minus)
		pad_char = '0';
	ne = n2 = (!par->unsign && *str == '-');
	if (ne && i < par->width && pad_char == '0' && !par->minus)
		str++;
	else
		ne = 0;
	if (par->plus && !n2 && !par->unsign)
		n += _putchar('+'), i++;
	else if (par->space && !n2 && !par->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < par->width)
		n += _putchar(pad_char);
	return (n);
}
