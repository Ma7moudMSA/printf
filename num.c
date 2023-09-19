#include "main.h"

/**
* convert - fn name
* @num: start
* @base: basa
* @flags: check it
* @par: struct
*
* Return: the pointer
*/

char *convert(long int num, int base, int flags, paramst *par)
{
	static char *a;
	static char buf[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;
	(void) par;

	if (!(flags && CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';
	}

	a = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do {
		*--ptr = a[n % base];
		n /= base;
	} while (n != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}

/**
* print_unsigned - fn name
* @print: int
* @par: par struct
*
* Return: check
*/

int print_unsigned(va_list print, paramst *par)
{
	unsigned long l;

	if (par->l)
		l = (unsigned long)va_arg(print, long);
	else if (par->h)
		l = (unsigned short int)va_arg(print, int);
	else
		l = (unsigned int)va_arg(print, unsigned int);
	par->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, par), par));
}

/**
* print_address - fn name
* @print: struct name
* @par: another struct
*
* Return: check for return
*/

int print_address(va_list print, paramst *par)
{
	unsigned long int n = va_arg(print, unsigned long int);
	char *str, xx = 0;

	if (xx == 0)
		xx++;
	if (!n)
		return (_puts("nul)"));
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, par));
}
