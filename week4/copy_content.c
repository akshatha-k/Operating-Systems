#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int fp=open("myname.txt",O_RDWR);
	int fc=creat("copy.txt",S_IRWXU);
	//int fd=open("myname.txt", O_RDWR);
	char array[10];
	int n=read(fp,array,10);
	write(fc, array, strlen(array));
	close(fp);
	close(fc);
}