/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:46:30 by mllamas-          #+#    #+#             */
/*   Updated: 2023/10/05 16:09:28 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

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
