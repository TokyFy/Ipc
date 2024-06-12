/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:41:58 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/12 15:43:42 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct s_byte		t_byte;
typedef unsigned int		t_sizet;
typedef struct s_byte		t_byte;

struct						s_byte
{
	volatile sig_atomic_t	bits;
	volatile sig_atomic_t	size;
};

typedef struct s_server_state
{
	volatile sig_atomic_t	bit;
	volatile sig_atomic_t	server_pid;
	volatile sig_atomic_t	client_pid;
	t_list					*buffer_lst;
	volatile sig_atomic_t	bit_c;
}							t_server_state;

typedef struct s_client_state
{
	pid_t					server_pid;
	volatile sig_atomic_t	received;
}							t_client_state;
