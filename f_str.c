#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
int get_precision(const char *format, va_list args)
{
    int precision = -1;
    const char *p = format;
    bool var_precision = false;

    while (*p != '\0')
    {
        if (*p == '.')
	{
            p++;
            if (*p == '*')
	    {
                precision = va_arg(args, int);
                var_precision = true;
                p++;
            }
	    else if (isdigit(*p))
	    {
                precision = strtol(p, (char**)&p, 10);
            }
	    else
	    {
                precision = 0;
            }
            break;
        }
	else
	{
            p++;
        }
    }
    if (!var_precision && precision == -1)
    {
        precision = 0;
    }
    return precision;
}
