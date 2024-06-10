#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 42

typedef struct byte t_byte;
typedef int bool;
typedef unsigned int t_sizet;

struct byte {
	sig_atomic_t bits;
	sig_atomic_t size;	
};

typedef struct server_state
{
  sig_atomic_t bit;
  int server_pid;
  int client_pid;
  char *buffer;
} t_server_state;


volatile t_server_state g_state;
#define G_STATE g_state


void sigurs_handler(int sig, siginfo_t *info, void *context)
{
   G_STATE.bit = (sig == SIGUSR1);
   G_STATE.client_pid = info->si_pid;
}

void bits_handler()
{
  write(1,"~\n",2);
  static t_byte byte;
  byte.size++;

  if(G_STATE.bit)
     byte.bits |= (1u << (8 - byte.size));

  if(byte.size >= 8)
  {
    // add byte to the string
  }
  kill(G_STATE.client_pid , SIGUSR1);
}


int main()
{
	pid_t pid = getpid();
	printf("PID : %d\n" , pid);

	struct sigaction sa;
	sa.sa_sigaction = sigurs_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1 , &sa , NULL);
	sigaction(SIGUSR2 , &sa , NULL);

	while(1)
  {
		pause();
    bits_handler();
  }

	return 0;
}
