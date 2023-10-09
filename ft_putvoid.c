/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:59:06 by mllamas-          #+#    #+#             */
/*   Updated: 2023/10/05 17:06:19 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	num_len(unsigned long long nb, size_t len_base)
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

static size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	while (*s)
	{
		a++;
		s++;
	}
	return (a);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void			*b;
	unsigned char	*ptr;
	size_t			i;

	i = count * size;
	b = malloc(i);
	if (!b)
		return (b);
	ptr = b;
	while (i > 0)
	{
		ptr[i - 1] = 0;
		i--;
	}
	return ((void *)ptr);
}

static char	*ft_createstr(unsigned long long nb, char *base)
{
	int		len;
	int		len_base;
	char	*s;

	len_base = ft_strlen(base);
	len = num_len(nb, len_base);
	s = ft_calloc((len + 1), sizeof(char));
	if (!s)
		return (0);
	while (len)
	{
		s[len - 1] = base[nb % len_base];
		nb = nb / len_base;
		len--;
	}
	return (s);
}

void	ft_putvoid(void *ptr, size_t *count)
{
	unsigned long int	aux;
	const char			*str;

	aux = (unsigned long int)ptr;
	if (ptr == NULL)
		ft_putstr("0x0", count);
	else
	{
		ft_putstr("0x", count);
		str = ft_createstr(aux, "0123456789abcdef");
		ft_putstr(str, count);
		free((void *)str);
	}
}

/*
char			*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_putstr("0x", count);
	str = ft_aux_pf(ptr_address, "0123456789abcdef");
	ft_putstr(str, count);
	free(str);
	*/