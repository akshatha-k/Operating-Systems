#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *child_thread(void *param)
{
	int n=(int)param;
	int *arr=(int*)malloc(n*sizeof(int));
	arr[0]=0;
	arr[1]=1;
	int i=2;
	while(i<n)
	{
		arr[i]=arr[i-1]+arr[i-2];
		i++;
	}
	return (void *)arr;
}
int main(int argc, char* argv[])
{
	pthread_t thread;
	int *arr;
	void *temp;
	int n=atoi(argv[1]);
	pthread_create(&thread, 0, &child_thread, (void*)n);
	pthread_join(thread,&temp);
	arr=temp;
	for(int i=0; i<n;i++)
		printf(" %d \t",arr[i]);
}