#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
void main()
{
	int status;
	pid_t pid;
	pid= fork();
	if(pid== -1)
		printf("\n ERROR child not created");
	else if(pid == 0)
	{
		printf("\n Child");
		int child_pid=getpid();
		printf("%d",child_pid);
		exit(0);
	}
	else
	{
		wait(&status);
		printf("\n  Parent");
		int parent_pid=getpid();
		printf("%d",parent_pid);
	}
}