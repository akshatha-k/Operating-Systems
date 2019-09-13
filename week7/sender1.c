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
	int number;
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid==-1)
	{
		fprintf(stderr, "msgrcv failed with error : %d\n", errno);
		exit(EXIT_FAILURE);
	}
	while(running){
		printf("Enter some number : ");
		scanf("%d",&number);
		some_data.num=number;
		some_data.my_msg_type=1;
		int temp = number;
		if(msgsnd(msgid, (void*)&some_data,sizeof(number),0)== -1)
		{
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		if(number== -1){
			running=0;
		}
		
	}
	exit(EXIT_SUCCESS);
}