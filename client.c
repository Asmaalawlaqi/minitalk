/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:31:57 by asmalawl          #+#    #+#             */
/*   Updated: 2024/03/26 10:16:44 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	read_binary_form(int pid, char message)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (message & (1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		bits++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		read_binary_form(pid, message[i]);
		i++;
	}
	read_binary_form(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	i;
	int	server_pid;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (!ft_isdigit(argv[1][i++]) || ft_strlen(argv[1]) > 31)
			{
				write(1, "Invalid PID\n", 12);
				exit(0);
			}
			else if (argv[1][i] < '0' || (argv[1][i] >= 'a'
						&& argv[1][i] <= 'z') || (argv[1][i] >= 'A'
						&& argv[1][i] <= 'Z'))
				exit(0);
			i++;
		}
		server_pid = ft_atoi(argv[1]);
		send_message(server_pid, argv[2]);
		if (argv[1][i] == '\0')
			write(1, &argv[2], 1);
		return (0);
	}
}
