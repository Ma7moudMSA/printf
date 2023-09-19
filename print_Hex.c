#include "main.h"

/**
 * print_Hex - prints the Hexa representation of a number
 * @number: the number to be printed
 * @count: a pointer to the count of characters printed
 *
 * Returns: void
 */
void print_Hex(unsigned int number, int *count)
{
	char hexDigits[] = "0123456789ABCDEF";
	unsigned int mask = 0xF0000000;

	while (mask > 0)
	{
		unsigned int nibble = (number & mask) >> ((sizeof(unsigned int) * 8) - 4);
		(*count)++;
		putchar(hexDigits[nibble]);
		mask >>= 4;
	}
}
