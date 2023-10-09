/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:27:09 by mllamas-          #+#    #+#             */
/*   Updated: 2023/10/09 12:18:41 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *format, ...);
void	ft_putbase(unsigned long int nb, char *base, size_t *count);
void	ft_putnbr(int nb, size_t *count);
void	ft_putstr(char const *s, size_t *count);
void	ft_putchar(char c, size_t *count);
void	ft_putvoid(void *ptr, size_t *count);
char	*ft_aux_pf(unsigned long long n, char *base);

#endif
