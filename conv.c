#include "main.h"

/**
* print_hex - prints hex in lc
* @print: argument ptr
* @par: struct
*
* Return: bytes printed
*/

int print_hex(va_list print, paramst *par)
{
	unsigned long lime;
	int check = 0;
	char *ptr_s;

	if (par->l)
		lime = (unsigned long)va_arg(print, unsigned long);
	else if (par->h)
		lime = (unsigned short int)va_arg(print, unsigned int);
	else
		lime = (unsigned int)va_arg(print, unsigned int);

	ptr_s = convert(lime, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	if (par->hashtag && lime)
	{
		*--ptr_s = 'x';
		*--ptr_s = '0';
	}
	par->unsign = 1;
	return (check += print_number(ptr_s, par));
}

/**
* print_HEX - prints hex in lc
* @print: argument ptr
* @par: struct
*
* Return: bytes printed
*/

int print_HEX(va_list print, paramst *par)
{
	unsigned long lime;
	int check = 0;
	char *ptr_s;

	if (par->l)
		lime = (unsigned long)va_arg(print, unsigned long);
	else if (par->h)
		lime = (unsigned short int)va_arg(print, unsigned int);
	else
		lime = (unsigned int)va_arg(print, unsigned int);

	ptr_s = convert(lime, 16, CONVERT_UNSIGNED, par);
	if (par->hashtag && lime)
	{
		*--ptr_s = 'X';
		*--ptr_s = '0';
	}
	par->unsign = 1;
	return (check += print_number(ptr_s, par));
}

/**
* print_binary - fn name
* @print: arg pointer
* @par: struct
*
* Return: bytes returned
*/

int print_binary(va_list print, paramst *par)
{
	unsigned int n = va__arg(print, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, par);
	int c = 0;

	if (par->hashtag && n)
		*--str = '0';
	par->unsign = 1;
	return (c += print_number(str, par));
}

/**
* print_octal - fn name
* @print: arg pounter
* @par: struct ptr
*
* Return: check for byted
*/

int print_octal(va_list print, paramst *par)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (par->l)
		l = (unsigned long)va_arg(print, unsigned long);
	else if (par->h)
		l = (unsigned short int)va_arg(print, unsigned int);
	else
		l = (unsigned int)va_arg(print, unsigned int);
	str = convert(1, 8, CONVERT_UNSIGNED, par);

	if (par->hashtag && l)
		*--str = '0';
	par->unsign = 1;
	return (c += print_number(str, par));
}
