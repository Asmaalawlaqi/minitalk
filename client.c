/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:21:10 by asmalawl          #+#    #+#             */
/*   Updated: 2024/03/26 11:12:36 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	send_m(char *m, int pid)
{
	int	i;
	int	x;
	int	shift;

	i = 0;
	while (m[i] != '\0')
	{
		x = m[i];
		shift = 0;
		while (shift < 8)
		{
			if ((x >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(350);
			shift++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*m;

	if (ac != 3)
	{
		ft_printf("invalid parameter\n", av[0]);
		return (0);
	}
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("invalid pid\n");
		exit(0);
	}
	m = av[2];
	send_m(m, pid);
	send_m("\n", pid);
	exit(0);
}
