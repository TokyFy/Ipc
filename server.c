/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:22:23 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/12 11:45:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_server_state	g_state;
#define G_STATE g_state

void	sigurs_handler(int sig, siginfo_t *info, void *context)
{
	(void)(info);
	(void)(context);
	G_STATE.bit = (sig == SIGUSR1);

 	G_STATE.client_pid = info->si_pid;
}

void loging()
{
  write(1, "\e[1;1H\e[2J", 11);

  write(1, "PID : ", 6);
	ft_putnbr_fd(G_STATE.server_pid, 1);
	write(1, " \n\nByte received : ", 18);
  ft_putnbr_fd(G_STATE.bit_c, 1);
  write(1, "\n", 1);
}

void write_c(void *ptr)
{
  write(1, (char *)ptr, 1);
}

void	save_byte(char a)
{
  G_STATE.bit_c++;

  char *c = malloc(sizeof(char));
  *c = a;

  ft_lstadd_back(&G_STATE.buffer_lst, ft_lstnew(c));

  loging();

	if (!a)
	{
    ft_lstiter(G_STATE.buffer_lst, write_c);
    ft_lstclear(&G_STATE.buffer_lst, free);
    G_STATE.buffer_lst = NULL;
	}
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
			free(G_STATE.buffer);
			G_STATE.buffer = NULL;
      G_STATE.bit_c = 0;
			kill(G_STATE.client_pid, SIGUSR2);
			return ;
		}
		byte.bits = 0;
		byte.size = 0;
	}
	usleep(15);
	kill(G_STATE.client_pid, SIGUSR1);
}


int	main(void)
{
	struct sigaction	sa;

	G_STATE.server_pid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr_fd(G_STATE.server_pid, 1);
	write(1, " \n", 2);

  G_STATE.buffer = NULL;
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
