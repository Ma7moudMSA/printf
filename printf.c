#include "main.h"

/**
 * _printf - printf function
 * 
 * @format: format.
 * 
 *  Return: Printed chars.
 */
/*
*by mahmoud medhat and moumen ibrahim
*/

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    for (const char *traverse = format; *traverse != '\0'; traverse++) {
        while (*traverse != '%' && *traverse != '\0') {
            putchar(*traverse);
            traverse++;
            count++;
        }

        if (*traverse == '\0') break;

        switch (*++traverse) {
            case 'c': {
                int c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            }
            case 's': {
                char *s = va_arg(args, char *);
                for (; *s; s++) {
                    putchar(*s);
                    count++;
                }
                break;
            }
            case '%': {
                putchar('%');
                count++;
                break;
            }
        }
    }

    va_end(args);
    return count;
}

