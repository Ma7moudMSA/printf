#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define params_init {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define NULL_STRING "(null)"

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

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
	unsigned int width;
	unsigned int precision;
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
	int (*function)(va_list, paramst *par);
} sf_t;

char *get_precision(char *str, paramst *par, va_list print);

char *convert(long int num, int base, int flags, paramst *par);
int print_unsigned(va_list print, paramst *par);
int print_address(va_list print, paramst *par);


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

int print_from_to(char *start, char *stop, char *except);
int print_rot13(va_list print, paramst *par);

int (*get_spec(char *s))(va_list print, paramst *par);
int get_print_function(char *s, va_list print, paramst *par); 
int get_flag(char *s, paramst *par);
int get_modifier(char *s, paramst *par);
char *get_width(char *s, paramst *p, va_list print);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, paramst *par);
int print_number_right_shift(char *str, paramst *par);
int print_number_left_shift(char *str, paramst *par);



#endif
