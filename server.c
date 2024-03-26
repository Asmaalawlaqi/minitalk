/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:13:48 by asmalawl          #+#    #+#             */
/*   Updated: 2024/01/23 12:23:47 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_received(int signal_pid)
{
	static int	collected_bits;
	static int	received_bits;

	if (signal_pid == SIGUSR1)
		collected_bits = collected_bits | (1 << received_bits);
	received_bits++;
	if (received_bits == 8)
	{
		write(1, &collected_bits, 1);
		received_bits = 0;
		collected_bits = 0;
	}
}

int	main(void)
{
	write(1, "server PID : ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_received);
	signal(SIGUSR2, signal_received);
	while (1)
		pause();
	write(1, "\n", 1);
}
