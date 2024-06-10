/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <tokyfy@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:07:12 by franaivo          #+#    #+#             */
/*   Updated: 2024/06/09 17:56:19 by franaivo         ###   ########.fr       */
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


char *buffer = NULL;
pid_t server_pid = 0;
#define GLOBAL_BUFFER buffer


void sigurs_handler(int sig, siginfo_t *info, void *context) {
   return;
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
    
    while (1) {
      kill(server_pid , SIGUSR1);
      pause();
    }

    return 0;
}
