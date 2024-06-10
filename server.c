/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:22:23 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/10 15:22:27 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile t_server_state	g_state;
#define G_STATE g_state

void	sigurs_handler(int sig, siginfo_t *info, void *context)
{
	G_STATE.bit = (sig == SIGUSR1);
	G_STATE.client_pid = info->si_pid;
}

void	save_byte(char a)
{
	static int	index = 0;
	char		*mem;

	if ((index) % BUFFER_SIZE == 0)
	{
		mem = calloc(sizeof(char), index + BUFFER_SIZE + 1);
		strcpy(mem, G_STATE.buffer);
		G_STATE.buffer = mem;
	}
	(G_STATE.buffer)[index] = a;
	if (!a)
	{
		write(1, G_STATE.buffer, index);
		free(G_STATE.buffer);
		G_STATE.buffer = calloc(sizeof(char), BUFFER_SIZE);
		index = 0;
	}
	if (a)
		index++;
}

void	bits_handler(void)
{
	static t_byte	byte;

	byte.size++;
	if (G_STATE.bit)
		byte.bits |= (1u << (8 - byte.size));
	if (byte.size == 8)
	{
		save_byte(byte.bits);
		if (!byte.bits)
		{
			byte.bits = 0;
			byte.size = 0;
			kill(G_STATE.client_pid, SIGUSR2);
			return ;
		}
		byte.bits = 0;
		byte.size = 0;
	}
	usleep(5);
	kill(G_STATE.client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	printf("PID : %d\n", pid);
	sa.sa_sigaction = sigurs_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	G_STATE.buffer = calloc(sizeof(char), BUFFER_SIZE);
	while (1)
	{
		pause();
		bits_handler();
	}
	return (0);
}
