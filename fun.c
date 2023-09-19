#include "main.h"

/**
* print_char - fn name
* @print: argument
* @p: pointer name
*
* Return: check length
*/

int print_char(va_list print, paramst *p)
{
	char pad_char = ' ', xx = 0;
	unsigned int pad = 1, sum = 0, ch = va_arg(print, int);

	if (p->minus)
		sum += _putchar(pad_char);
	while (pad++ < p->width)
		sum += _putchar(pad_char);
	if (p->minus)
		sum += _putchar(ch);
	xx++;
	return (sum);
}

/**
* print_string - fn name
* @print: argument
* @p: pointer name
*
* Return: check length
*/

int print_string(va_list print, paramst *p)
{
	char *str = va_arg(print, char *), pad_char = ' ', xx = 0;
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)p;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (p->precision < pad)
		j = pad = p->precision;

	if (p->minus)
	{
		if (p->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
		xx++;
	}
	while (j++ < p->width)
		sum += _putchar(pad_char);
	if (!p->minus)
	{
		if (p->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
* print_percent - fn name
* @print: argument
* @p: pointer name
*
* Return: check length
*/
int print_percent(va_list print, paramst *p)
{
	(void)print;
	(void)p;
	return (_putchar('%'));
}

/**
* print_int - fn name
* @print: argument
* @p: pointer name
*
* Return: check length
*/
int print_int(va_list print, paramst *p)
{
	long l;

	if (p->l)
		l = va_arg(print, long);
	else if (p->h)
		l = (short int)va_arg(print, int);
	else
		l = (int)va_arg(print, int);
	return (print_number(convert(l, 10, 0, p), p));
}

/**
* print_S - fn name
* @print: argument
* @p: pointer name
*
* Return: check length
*/

int print_S(va_list print, paramst *p)
{
	char *str = va_arg(print, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, p);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(*str);
	}
	return (sum);
}
