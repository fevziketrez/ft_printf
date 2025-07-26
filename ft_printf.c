#include "ft_printf.h"

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
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return ft_putstr("(null)");
	else
	{
		while(str && str[i])
		{
			res += ft_putchar(str[i]);
			i++;
		}
	}
	return (res);
}
int	ft_putnbrbase(unsigned long num, char *base)
{
	unsigned long base_len;
	int count;

	count = 0;
	base_len = ft_strlen(base);
	if (num > base_len - 1)
	{
		count += ft_putnbrbase(num / base_len, base);
		count += ft_putnbrbase(num % base_len, base);
	}
	else
		count += ft_putchar(base[num]);
	return count;
}

int	ft_putnbr( int num)
{
	int		count;
	long	nb;

	nb = num;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar('-');
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return count;
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbrbase((unsigned long)ptr, "0123456789abcdef");
	}
	return (count);
}

static int	format_dec(char c, va_list ap)
{
	int count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putnbrbase(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		count += ft_putnbrbase(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbrbase(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	// char c = 'X'; ///
	va_start(ap, format);
	while(*format)
	{
		if(*format == '%')
			count += format_dec(*(++format), ap);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return count;
}

// #include <stdio.h>
// int	main()
// {
// // 	int output_OG;
// // 	int output_FT;
// // 	// unsigned int my_num = 16;
// // 	// ft_printf("first arg:%d ft_\n", 0);
// // 	// printf("first arg:%d orji\n", 0);
// // 	// ft_printf("first arg:%i ft_\n", -1);
// // 	// printf("first arg:%i orji\n", -1);
// // 	// ft_printf("first arg:%p ft_\n", &my_num);
// // 	// printf("first arg:%p orji\n", &my_num);

// // 	// ft_printf("chars:%s \n %d\n", "abc", 1);
// // 	// printf("chars:%s \n %s\n", "abc", "def");

// // 	ft_printf("--------------------------------MIX-------------------------------\n");
// // 	output_OG = printf("OG -> %%%s %%%s %%%d %clbum \t 520 in hexadecimal is %x\n", "string1", "string2", 18, 'a', 520);
// // 	output_FT = ft_printf("FT -> %%%s %%%s %%%d %clbum \t 520 in hexadecimal is %x\n", "string1", "string2", 18, 'a', 520);
// // 	printf("OUTPUT OG = %d\n", output_OG);
// // 	ft_printf("OUTPUT FT = %d\n", output_FT);
// 	char *test = NULL;
// 	printf(" NULL %s NULL \n", test);
// 	ft_printf(" NULL %s NULL \n", test);

// 	void *test2 = NULL;
// 	printf(" NULL %p NULL \n", test2);
// 	ft_printf(" NULL %p NULL \n", test2);

// }
