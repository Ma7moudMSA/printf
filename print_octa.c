#include "main.h"
/**
 * print_octa - prints the octal representation of a number
 * @number: the number to be printed
 * @count: a pointer to the count of characters printed
 */
void print_octa(unsigned int number, int *count)
{
	if (number == 0)
	{
		putchar('0');
		(*count)++;
	}
	else
	{
		char octalDigits[12];
		int index = 0;

		while (number > 0)
		{
			octalDigits[index++] = (number % 8) + '0';
			number /= 8;
		}

		for (int i = index - 1; i >= 0; i--)
		{
			putchar(octalDigits[i]);
			(*count)++;
		}
	}
}
