#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 2

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
	byte->size++;
  if(bit)
	  byte->bits |= (1u << (8 - byte->size));
}

void append_byte(t_byte *byte)
{	
//  char *s = GLOBAL_BUFFER;
//	t_sizet len = strlen(s);

//  if(byte->bits ==  '\0')
//  {
//    write(1, s, BUFFER_SIZE);
//    bzero(GLOBAL_BUFFER, BUFFER_SIZE + 1);
//    byte->size = 0;
//    byte->bits = 0;
//    return;
//  }
//
//  if(len == BUFFER_SIZE)
//  {
//    write(1, s, BUFFER_SIZE);
//    bzero(GLOBAL_BUFFER, BUFFER_SIZE + 1);
//    return append_byte(byte);
//  }
//
//	s[++len - 1] = (char)byte->bits;	
	byte->size = 0;
	byte->bits = 0;
}

void handle_sigurs1(int sig, siginfo_t *info, void *context)
{
	static t_byte byte = {0 , 0};
	
	append_bit(&byte , sig == SIGUSR1);
	if(byte.size != 8)
	  	return;

  write(1, &byte.bits, 1);
  
	append_byte(&byte);
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
