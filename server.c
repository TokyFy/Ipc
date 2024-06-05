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
	unsigned char bits;
	unsigned int size;	
};

char *buffer = NULL; 
#define GLOBAL_BUFFER buffer

void putnumber(int n)
{
  if(n <= 9)
  {
    char a = n + '0';
    write(1 , &a , 1);
    return;
  }
  
  putnumber(n / 10);
  putnumber(n % 10);
}

void append_bit(t_byte* byte , bool bit)
{
  write(1, "-", 1);
 	byte->size++;
  if(bit)
	  byte->bits |= (1u << (8 - byte->size));
}

void append_byte(t_byte *byte)
{	
  char *s = GLOBAL_BUFFER;
	t_sizet len = strlen(s);

  write(1, " ", 1);

  if(byte->bits ==  '\0')
  {
    write(1, s, len);
    byte->size = 0;
    byte->bits = 0;
    free(s);
    GLOBAL_BUFFER = malloc(BUFFER_SIZE);
    bzero(GLOBAL_BUFFER, BUFFER_SIZE);
    return;
  }

 if(len % BUFFER_SIZE == 0)
 {
   char* temp = malloc(sizeof(char) * len + BUFFER_SIZE + 1);
   bzero(temp, len + BUFFER_SIZE + 1);
   strncpy(temp, s, len + 1);
   free(s);
   GLOBAL_BUFFER = temp;
   s = GLOBAL_BUFFER;
 }

	s[++len - 1] = (char)byte->bits;	
	byte->size = 0;
	byte->bits = 0;
}

void handle_sigurs1(int sig, siginfo_t *info, void *context)
{
	static t_byte byte = {0 , 0};
	append_bit(&byte , sig == SIGUSR1);
  kill(info->si_pid, SIGUSR1);
	if(byte.size != 8)
	  	return;
	append_byte(&byte);
  if(!byte.bits)
  {
    kill(info->si_pid, SIGUSR2);
  }
}


int main()
{
	pid_t pid = getpid();
	printf("PID : %d\n" , pid);
	GLOBAL_BUFFER = calloc(sizeof(char) , BUFFER_SIZE + 1);

	struct sigaction sa;
	sa.sa_sigaction = handle_sigurs1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1 , &sa , NULL);
	sigaction(SIGUSR2 , &sa , NULL);

	while(1)
		pause();

	return 0;
}
