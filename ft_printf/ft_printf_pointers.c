/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:23:47 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/19 12:39:12 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer(unsigned long p)
{
	char	str[16];
	char	*base_char;
	int		i;
	int		j;

	i = 0;
	base_char = "0123456789abcdef";
	write(1, "0x", 2);
	if (p == 0)
	{
		ft_putchar('0');
		return (3);
	}
	while (p != 0)
	{
		str[i] = base_char[p % 16];
		p = p / 16;
		i++;
	}
	j = i;
	while (i--)
		ft_putchar(str[i]);
	return (j + 2);
}
