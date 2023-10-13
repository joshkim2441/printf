#include "main.h"

/**
 * get_size - to calculate size for casting the argument
 * @format: formatted string in which arguments are printed.
 * @i: the arguments list to be printed.
 *
 * Return: precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size_g = 0;

	if (format[curr_i] == 'l')
		size_g = S_LONG;
	else if (format[curr_i] == 'h')
		size_g = S_SHORT;

	if (size_g == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size_g);
}
