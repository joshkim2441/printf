#include "main.h"

/**
 * ptintf - produces output according to a format
 * @format: a character string
 * Retuen: the number od characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	va_start(args, format);

	for (const char *traverse = format; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%'; && *traverse != '\0')
		{
			putchar(*traverse);
			traverse++;
			count++;
		}
		if (*traverse == '\0')
			break;
		switch (*traverse)
		{
			case 'c':
				{
					int c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
			case 's':
				{
					char *s = va_arg(args, char*);
					for (; *s; s++)
					{
						putchar(*s);
						count++;
					}
					break;
				}
			case '%':
				{
					putchar('%');
					count++;
					break;
				}
		}

	}

	va_end(args);
	return (count);
}

/**
 * _printf - hanldes precision for non-custom conversion specifiers
 * @format: the format to convert to
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	va_start(args, format);

	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			count++;
			continue;
		}

		p++;

		int precision = -1;
		if (*p >= '0' && *p <= '9')
		{
			precision = *p - '0';
			p++;
		}

		switch (*p)
		{
			case 'c':
				{
					char c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
			case 's':
				{
					char *s = va_arg(args, char *);
					for (char *sp = s; *sp != '\0' && (precision == -1 || sp - s < precision); sp++)
					{
						putchar(*sp);
						count++;
					}
					break;
				}
			default:
				{
					putchar('%');
					if (precision != -1)
					{
						_putchar('0' + precision);
					}
					putchar(*p);
					count += 2 + (precision != -1 ? 1 : 0);
					break;
				}
		}
	}

	va_end(args);

	return (count);
}
