/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:07:12 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/10 13:55:23 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 42

typedef struct byte t_byte;
typedef int bool;
typedef unsigned int t_sizet;

struct byte {
    unsigned char bits;
    unsigned int size;
};

pid_t server_pid = 0;
volatile sig_atomic_t received = 0;


void sigurs_handler(int sig, siginfo_t *info, void *context) {
   if(sig == SIGUSR1)
   {
      received = 1;
   }
   if(sig == SIGUSR2)
    exit(0);
   return;
}

void send_byte(unsigned char byte , pid_t pid)
{
   int bit_index = 0;
   while(bit_index++ < 8)
   {
    usleep(25);
    if(byte & (1u << (8 - bit_index)))
    {
       kill(pid, SIGUSR1);
    } 
    else
    {
       kill(pid, SIGUSR2);
    }
    if(!received) {
      pause();
      received = 0;
    }
   } 
}

int main(int argc, char **argv) {
  if (argc != 3)
      return 1;

  server_pid = atoi(argv[1]);

  struct sigaction sa;
	sa.sa_sigaction = sigurs_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1 , &sa , NULL);
	sigaction(SIGUSR2 , &sa , NULL);

  char *str = argv[2];

  while (1) {
    send_byte(*(str), server_pid);
    if(!*str)
        break;

    str++;
  }
  return 0;
}
