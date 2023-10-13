#include "main.h"

/******************TO PRINT POINTER ******************/
/**
 * print_pointer - it prints the value of a pointer variable
 * @types: lists arguments
 * @buffer: a buffer array to handle printing
 * @flags:  Calculates active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* TO PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - it prints ascii codes in hexa of non printable chars
 * @types: lists arguments
 * @buffer: a buffer array to handle print
 * @flags:  it calculates active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (is_printable(str[x]))
			buffer[x + offset] = str[x];
		else
			offset += append_hexa_code(str[x], buffer, x + offset);

		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}

/************************* TO PRINT REVERSE *************************/
/**
 * print_reverse - it Prints reverse string.
 * @types: lists arguments
 * @buffer: a buffer array to handle printing
 * @flags:  it alculates the active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = str[x];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/*************************TO PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - it print a string in rot13.
 * @types: lists arguments
 * @buffer: a buffer array to handle print
 * @flags:  it calculates active flags
 * @width: gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, v;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (v = 0; in[v]; v++)
		{
			if (in[v] == str[i])
			{
				x = out[v];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[v])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
