#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	int num;
};

int main()
{
	int running=1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_receive=0;
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid==-1)
	{
		fprintf(stderr, "msgrcv failed with error : %d\n", errno);
		exit(EXIT_FAILURE);
	}
	while(running){
		if(msgrcv(msgid, (void*)&some_data, sizeof(some_data.num), msg_to_receive,0)== -1)
		{
			fprintf(stderr, "msgrcv failed with error %d\n", errno);
			exit(EXIT_FAILURE);
		}
		if(some_data.num==-1)
		{
			running=0;
			break;
		}
		printf("You wrote : %d", some_data.num);
		int pal=0;
		int temp=some_data.num;
		while(some_data.num!=0)
		{
			pal=pal*10+some_data.num%10;
			some_data.num =some_data.num/10;
		}
		if(pal==temp)
		{
			printf("Palidrome !! \n");
		}
		else
		{
			printf("Not a Palidrome !! \n");
		}
		
	}
	if(msgctl(msgid, IPC_RMID,0)==-1)
	{
		fprintf(stderr,"msgctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}