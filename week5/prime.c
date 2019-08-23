#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int count =0;
void *child_thread(void *param)
{
	int flag, *primes;
	int *arr=(int*)(param);
	int low=arr[0];
	int high=arr[0];
	while (low < high)
    {
        flag = 0;
        for(int i = 2; i <= low/2; ++i)
        {
            if(low % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            primes[count]=low;
            count++;
        }
        ++low;
    }
	return (void *)primes;
}
int main(int argc, char* argv[])
{
	pthread_t thread;
	int *arr;
	void *temp;
	arr[0]=atoi(argv[1]);
	arr[1]=atoi(argv[2]);
	pthread_create(&thread, 0, &child_thread, (void*)arr);
	pthread_join(thread,&temp);
	arr=temp;
	for(int i=0; i<count;i++)
		printf(" %d \t",arr[i]);
}