#include "main.h"

/**
* init_par - fn name
* @par: the structure inside paramater
* @print: the pointer of the argument
*
* Return: void
*/

void init_par(paramst *par, va_list print)
{
	par->unsign = 0;
	par->plus = 0;
	par->space = 0;
	par->hashtag = 0;
	par->minus = 0;
	par->zero = 0;
	par->precision = UINT_MAX;
	par->width = 0;
	par->h = 0;
	par->l = 0;
	(void)print;
}
