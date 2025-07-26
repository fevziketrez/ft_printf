#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifdef __APPLE__
#  define NUL_STR "0x0"
#  define NUL_LEN 3
# elif __linux__
#  define NUL_STR "(null)"
#  define NUL_LEN 6
# else
#  define NUL_STR "(nil)"
#  define NUL_LEN 5
# endif

# include <unistd.h>
# include <stdarg.h>

int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbrbase(unsigned long num, char *base);
int	ft_putnbr(int num);
int	ft_putptr(void *ptr);
static int	format_dec(char c, va_list ap);
int	ft_printf(const char *format, ...);

#endif
