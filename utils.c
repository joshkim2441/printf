#include "main.h"

/**
 * is_printable - it evaluates if a char is printable.
 * @c: the char to evaluate
 *
 * Return: if c is printable 1, otherwise 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - appends ascci in hexadecimal code to the buffer.
 * @buffer: an array of chars
 * @i: the index at which to start appending
 * @ascii_code: the assci code
 * Return: Always 3 success
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - it verifies if a char is digit.
 * @c: the char to evaluate.
 *
 * Return: if c is a digit 1, otherwise 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - it casts a number to specified size.
 * @num: the number to cast
 * @size: the number indicating type to be cast
 *
 * Return: the cast value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - it casts a number to specified size.
 * @num: the number to cast
 * @size: the number indicating type to cast.
 *
 * Return: the cast value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
