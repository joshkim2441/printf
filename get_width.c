#include "main.h"

/**
 * get_width - it calculates width for printing
 * @format: the formatted string in which arguments are printed
 * @i: the list of arguments to be printed.
 * @list: arguments list
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int wid = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			wid *= 10;
			wid += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (wid);
}
