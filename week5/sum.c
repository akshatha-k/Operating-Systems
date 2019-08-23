#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *child_thread(void *param)
{
	int sum=0;
	int *arr=(int*)(param);
	int n= sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<n;i++)
		sum=sum+arr[i];
	return (void *)sum;
}
int main(int argc, char* argv[])
{
	pthread_t thread;
	int *arr,n;
	printf("Enter number of elements \n");
	scanf("%d",&n);
	printf("Enter the array of non negative integers \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	void *temp;
	pthread_create(&thread, 0, &child_thread, (void*)arr);
	pthread_join(thread,&temp);
	int sum=(int)temp;
	printf("The sum is: %d \n",sum);
}