/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:08:19 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/13 13:22:07 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_putnbrunsigned(unsigned long int n)
{
	if (n == (unsigned long)LONG_MIN)
		ft_putchar('0');
	if (n > 4294967295)
		ft_putnbrunsigned(4294967295);
	else if (n >= 10)
	{
		ft_putnbrunsigned(n / 10);
		ft_putnbrunsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
