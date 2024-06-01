#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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

void handle_sigurs1(int sig, siginfo_t *info, void *context)
{
  write(1,"SIGUSR1 [" , 9);
  putnumber(info->si_pid);
  write(1, "] \n", 3);
}

int main()
{
	pid_t pid = getpid();
	printf("PID : %d\n" , pid);
  
  struct sigaction sa;
  sa.sa_sigaction = handle_sigurs1;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;

  sigaction(SIGUSR1 , &sa , NULL);

	while(1)
	{
		pause();
	}

	return 0;
}
