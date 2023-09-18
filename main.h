#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define params_init (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define convert_lower		1
#define convert_unsigned	2

/**
* struct parameters - this is a struct of parameters
* @unsign: unsigned value flag
* @plus: plus flag
* @space: space flag
* @hashtag: hashtag flag
* @zero: zero flag
* @minus: minus flag
* @width: width flag
* @precision: precision flag
* @h: for the modifier of h
* @l: for the modifier of l
*/


typedef struct parameters
{
	unsigned int unsign	: 1;
	unsigned int plus	: 1;
	unsigned int space	: 1;
	unsigned int hashtag	: 1;
	unsigned int zero	: 1;
	unsigned int minus	: 1;
	unsigned int width	: 1;
	unsigned int precision	: 1;
	unsigned int h		: 1;
	unsigned int l		: 1;
} paramst;

/**
* struct spec_func - this is to choose between different for specifier
* @specifier: what format
* @function: which function to choose
*/

typedef struct spec_func
{
	char *specifier;
	int (*function)(va_list, paramst);
} sf_t




int _printf(const char *format, ...);
int _puts(char *str);
int _putchar(int c);




int print_char(va_list print, paramst *p);
int print_string(va_list print, paramst *p);
int print_percent(va_list print, paramst *p);
int print_int(va_list print, paramst *p);
int print_S(va_list print, paramst *p);

int print_hex(va_list print, paramst *p);
int print_HEX(va_list print, paramst *p);
int print_binary(va_list print, paramst *p);
int print_octal(va_list print, paramst *p);

int print_unsigned(va_list print, paramst *p);
int print_adress(va_list print, paramst *p);

int print_rev(va_list print, paramst *p);

void init_par(paramst *par, va_list print);

#endif
