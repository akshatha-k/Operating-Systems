#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int fp=open("words.txt",O_RDWR);
	char array[100];
	int wc=0, lc=0, chc=0;
	int n=read(fp,array,100);
	int i;
	while(chc!=strlen(array))
	{
		if(array[i]=='\n')
			lc++;
		else if(array[i]==' ')
		{
			wc++;
			chc++
		}
		else 
			chc++;
	}
	close(fp);
}