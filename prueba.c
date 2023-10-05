#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putchar(char c, size_t *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char const *s, size_t *count)
{
	int		i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putnbr(int nb, size_t *count)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', count);
		ft_putchar('2', count);
		ft_putnbr(147483648, count);
	}
	else if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
		ft_putnbr(nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
		ft_putchar(nb + 48, count);
}

static unsigned long int	num_len(unsigned int nb, unsigned long int len_base)
{
	unsigned long int	count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / len_base;
		count++;
	}
	return (count);
}

static unsigned long int	ft_strlen(char *s)
{
	unsigned long int	a;

	a = 0;
	while (*s)
	{
		a++;
		s++;
	}
	return (a);
}

static char const	*ft_createstr(unsigned long int nb, char *base)
{
	unsigned long int	len;
	unsigned long int	len_base;
	char				*s;

	len_base = ft_strlen(base);
	len = num_len(nb, len_base);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	s[len] = '\0';
	while (len)
	{
		s[len - 1] = base[nb % len_base];
		nb = nb / len_base;
		len--;
	}
	return ((const char *)s);
}

void	ft_putbase(unsigned long int nb, char *base, size_t *count)
{
	char const	*s;

    if (nb <= 0)
    {
        s = "0";
        ft_putstr(s, count);
    }
    else
    {
	    s = ft_createstr(nb, base);
	    ft_putstr(s, count);
	    free((void *)s);
    }
}

void	ft_putvoid(void *ptr, size_t *count)
{
	unsigned long int	aux;

	aux = (unsigned long int)ptr;
	ft_putstr("0x", count);
	ft_putbase(aux, "0123456789abcdef", count);
}

void	ft_format(char const *format, va_list args, size_t *count)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(args, const char *), count);
	else if (*format == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (*format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*format == 'p')
		ft_putvoid(va_arg(args, void *), count);
	else if (*format == 'u')
		ft_putbase(va_arg(args, unsigned int), "0123456789", count);
	else if (*format == 'x')
		ft_putbase(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (*format == 'X')
		ft_putbase(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (*format == '%')
		ft_putchar('%', count);
	else
		return ;
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	count;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(format, args, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	int a;
	int b;

//	a = ft_printf("Char %c, string %s, int %d, int %i, unsigne %u", 'c', "sete", -123, 123, 124512);
//	a = ft_printf("Char %c, string %s, int %d, int %i, unsigned 10 %u, ex mi
//	n %x, ex may %X, porcen %%\n", 'c', "sete", -1224, 123, 1247, 787, 787);
	a = ft_printf("%p", "");
	printf("%d\n", a);
	b = printf("%p", "");
	printf("%d\n", b);
	return (0);
}
