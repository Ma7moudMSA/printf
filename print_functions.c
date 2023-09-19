#include "main.h"

/**
* print_from_to - fn name
* @start: where ptr starts
* @stop: where it should end
* @except: the except address
*
* Return: number of bytes printed
*/

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
* print_rev - fn name
* @print: my list
* @par: struct
*
* Return: number of bytes
*/

int print_rev(va_list print, paramst *par)
{
	int l, s = 0;
	char *ptr = va_arg(print, char*);
	(void) par;

	if (ptr)
	{
		for (l = 0; *ptr; ptr++)
			l++;
		for (; l > 0; l--, ptr--)
			s += _putchar(*ptr);
	}
	return (s);
}

/**
* print_rot13 - fnn name
* @print: struct
* @par: check it out
*
* Return: number of bytes
*/

int print_rot13(va_list print, paramst *par)
{
	int i, check;
	int c = 0;

	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";

	char *a = va_arg(print, char *);

	(void)par;

	i = 0;
	check = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
			|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			check = a[i] - 65;
			c += _putchar(arr[check]);
		}
		else
			c += _putchar(a[i]);
		i++;
	}
	return (c);
}
