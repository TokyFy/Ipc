/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:41:58 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/12 11:39:18 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct s_byte		t_byte;
typedef unsigned int		t_sizet;
typedef struct s_byte		t_byte;

struct						s_byte
{
	sig_atomic_t			bits;
	sig_atomic_t			size;
};

typedef struct s_server_state
{
	sig_atomic_t			bit;
	sig_atomic_t			server_pid;
	sig_atomic_t			client_pid;
	char					*buffer;
  t_list *buffer_lst;
  sig_atomic_t bit_c;
}							t_server_state;

typedef struct s_client_state
{
	pid_t					server_pid;
	volatile sig_atomic_t	received;
}							t_client_state;
