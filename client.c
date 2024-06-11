/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:07:12 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/11 10:05:25 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

volatile t_client_state	g_state;
#define G_STATE g_state

void	sigurs_handler(int sig, siginfo_t *info, void *context)
{
	(void)(info);
	(void)(context);
	if (sig == SIGUSR1)
	{
		G_STATE.received = 1;
	}
	if (sig == SIGUSR2)
		exit(0);
	return ;
}

void	send_byte(unsigned char byte, pid_t pid)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index++ < 8)
	{
		usleep(1);
		if (byte & (1u << (8 - bit_index)))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		if (!G_STATE.received)
		{
			pause();
			G_STATE.received = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	char				*str;

	if (argc != 3)
		return (1);
	G_STATE.server_pid = atoi(argv[1]);
	if (kill(G_STATE.server_pid, 0))
	{
		write(1, "Error : Server not found\n", 25);
		return (1);
	}
	sa.sa_sigaction = sigurs_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	str = argv[2];
	while (1)
	{
		send_byte(*(str), G_STATE.server_pid);
		if (!*str)
			break ;
		str++;
	}
	return (0);
}
