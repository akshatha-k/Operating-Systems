#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void main()
{
	execlp("./wait_child1","wait_child1", NULL);
}