#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
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
		exit(0);
	}
	else
	{
		sleep(5);
		printf("\n Parent running");
	}
}