#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 *_printf-function that produces output according to a format.
 *@format: the string of characters to write to buffer
 *Return: the number of characters printed (excluding the null
 *		byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	va_list vlist;
	buffer *buf;

	buf = buf_new();
	if (buf == NULL)
		return (-1);
	if (format == NULL)
		return (-1);

	va_start(vlist, format);
	while (format[i])
	{
		buf_wr(buf);

		if (format[i] == '%')
		{
			j = opid(buf, vlist, format, i);
			if (j < 0)
			{
				i = j;
				break;
			}
			i += j;
			continue;
		}

		buf->str[buf->index] = format[i];
		buf_inc(buf);
		i++;

	}
		buf_write(buf);
			if (j >= 0)
				i = buf->overflow;
			buf_end(buf);
			va_end(vlist);
			return (i);
}
