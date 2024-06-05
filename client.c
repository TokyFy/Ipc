/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:07:12 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/05 20:14:46 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
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


char* buffer = NULL;
pid_t server_pid = 0;
#define GLOBAL_BUFFER buffer


void handle_sigurs1(int sig, siginfo_t *info, void *context)
{
    if(sig == SIGUSR2)
        exit(0);
   return;	
}


int main(int argc , char **argv)
{
  if(argc != 3)
    return 1;

  server_pid = atoi(argv[1]);
  GLOBAL_BUFFER = argv[2];
  t_sizet index = 0;
  t_sizet bit_index = 0;

	struct sigaction sa;
	sa.sa_sigaction = handle_sigurs1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1 , &sa , NULL);
	// sigaction(SIGUSR2 , &sa , NULL);

  t_sizet buff_len = strlen(GLOBAL_BUFFER);
  printf("SERVER : %d\n" , server_pid);

	while(index == 0 || GLOBAL_BUFFER[index - 1])
  {
    if(bit_index++ < 8)
    {
        char byte = GLOBAL_BUFFER[index];
        if(byte & (1u << (7 - bit_index)))
        {
          write(1,"1",1);
          kill(server_pid, SIGUSR1);
        } 
        else
        {
          write(1,"0",1);
          kill(server_pid, SIGUSR2);
        }
    }
    else
    {
      index++;
      bit_index = 0;
      write(1, " " , 1);
      continue;
    }
   	pause();
  }

	return 0;
}
