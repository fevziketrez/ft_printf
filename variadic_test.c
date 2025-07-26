#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	int count;
	char *res;

	count = 0;
	char c = 'X';
	va_start(ap, format);
	{
		while(*format)
		{
			if(*format == '%')
			{
				write(1, &c, 1);
				write(1, &c, 1);
				format++;
			}
				// count += format_dec(*(++format));
			else count += write(1, format, 1);
				format++;
		}
	}
	va_end(ap);
	return count;
}

int	main()
{
	ft_printf("test %3 asd");
}
