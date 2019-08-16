#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int fp=creat("myname.txt",S_IRWXU);
	//int fd=open("myname.txt", O_RDWR);
	char array[]="naruto \n";
	write(fp, array, strlen(array));
	close(fp);
}