#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int i;
	int	res;

	i = 0;
	res = 0;
	while(str[i])
	{
		res += ft_putchar(str[i]);
		i++;
	}
	return (res);
}
int	t_putnbrbase(unsigned int num, char *base)
{
	return 0;
}

int	format_dec(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	// else if (c == 'p')
	// 	//
	// 	return 0;
	// else if (c == 'd')
	// 	return (0);
	// 	// ft_putnbrbase(va_arg(ap, int));					//int conv
	// else if (c == 'i')
	// 	return (0);
	// 	//ft_putnbrbase(va_arg(ap, int)); 					//int conv
	// else if (c == 'u')
	// 	// ft_putnbrbase(va_arg(ap, unsigned int), "0123456789"); //unsigned
	// else if (c == 'x')
	// 	// ft_putnbrbase(va_arg(ap, unsigned int), "0123456789abcdef");
	// else if (c == 'X')
	// 	// ft_putnbrbase(va_arg(ap, unsigned int), "0123456789ABCDEF");
	// else if (c == '%')
	// 	ft_putchar('%');
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*res;

	count = 0;
	char c = 'X'; ///
	va_start(ap, format);
	{
		while(*format)
		{
			if(*format == '%')
			{
				// count += format_dec(*(++format), ap);

				// write(1, &c, 1);
				// write(1, &c, 1);
				format++;
				char *mystr = va_arg(ap, char *);
				printf("%s", mystr);
			}
			else count += write(1, format, 1);
				format++;
		}
	}
	va_end(ap);
	return count;
}

int	main()
{
	ft_printf("test %s asd", "123\n");
}
