/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:22:23 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/13 11:52:48 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server_state	g_state;
#define G_STATE g_state

void	sigurs_handler(int sig, siginfo_t *info, void *context)
{
	(void)(info);
	(void)(context);
	G_STATE.bit = (sig == SIGUSR1);
	G_STATE.client_pid = info->si_pid;
}

void	loging(void)
{
	write(1, "\e[1;1H\e[2J", 11);
	write(1, "PID : ", 6);
	ft_putnbr_fd(G_STATE.server_pid, 1);
	write(1, " \n\nByte received : ", 18);
	ft_putnbr_fd(G_STATE.bit_c, 1);
	write(1, "\n", 1);
}

void	save_byte(char a)
{
	char	*c;

	G_STATE.bit_c++;
	c = malloc(sizeof(char));
	*c = a;
	ft_lstadd_back(&G_STATE.buffer_lst, ft_lstnew(c));
	loging();
}

void	bits_handler(void)
{
	static t_byte	byte;

	byte.size++;
	if (G_STATE.bit)
		byte.bits |= (1u << (8 - byte.size));
	if (byte.size == 8)
	{
		if (!byte.bits)
		{
			byte.bits = 0;
			byte.size = 0;
			G_STATE.bit_c = 0;
			ft_lstiter(G_STATE.buffer_lst, write_c);
			ft_lstclear(&G_STATE.buffer_lst, free);
			G_STATE.buffer_lst = NULL;
			usleep(50);
			kill(G_STATE.client_pid, SIGUSR2);
			return ;
		}
		save_byte(byte.bits);
		byte.bits = 0;
		byte.size = 0;
	}
	usleep(50);
	kill(G_STATE.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	G_STATE.server_pid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(G_STATE.server_pid, 1);
	write(1, " \n", 2);
	G_STATE.bit = 0;
	G_STATE.bit_c = 0;
	sa.sa_sigaction = sigurs_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		bits_handler();
	}
	return (0);
}
