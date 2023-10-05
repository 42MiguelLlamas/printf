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

void	ft_putvoid(void *ptr, size_t *count)
{
	unsigned int	aux;

	aux = (unsigned int)ptr;
	ft_putstr("0x", count);
	ft_putbase(aux, "0123456789abcdef", count);
}
