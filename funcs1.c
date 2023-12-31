#include "main.h"

/*************************TO PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - it prints unsigned number
 * @types: a list of arguments
 * @buffer: a buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************* TO PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - it prints unsigned number in octal notation
 * @types: lists arguments
 * @buffer: a buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************** TO PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - it prints an unsigned number in hexadecimal notation
 * @types: lists the arguments
 * @buffer: a buffer array to handle print
 * @flags:  it calculates the active flags
 * @width: it gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/****** TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - it prints an unsigned number
 * in upper hexadecimal notation
 * @types: lists arguments
 * @buffer: a buffer array to handle printing
 * @flags:  it calculates the active flags
 * @width: it gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**************TO PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - it prints a hexadecimal number in lower or upper
 * @types: lists arguments
 * @map_to: an array of values to map the number to
 * @buffer: the buffer array to handle print
 * @flags:  it calculates the active flags
 * @flag_ch: it calculates active flags
 * @width: it gets the width
 * @precision: the precision specification
 * @size: the size specifier
 * @size: the size specification
 * Return: the number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
