#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - to prints a char
 * @types: the list of arguments
 * @buffer: a buffer array to handle printing.
 * @flags: it calculates the active flags
 * @width: the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - to print a string
 * @types: an arguments list
 * @buffer: the buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets the width.
 * @precision: the precision specification
 * @size: a size specifier
 * Return: the number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - it prints percent sign
 * @types: Lists arguments
 * @buffer: the buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets width.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - prints an int
 * @types: lists arguments
 * @buffer: a buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets the width.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - it prints unsigned number
 * @types: lists arguments
 * @buffer: a buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets the width.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the umbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = x / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (x / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
