#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int m,n;
void printMem(int arr[])
{
	printf("Memory : ");
	for(int i=0;i<m;i++)
		printf("%d	",arr[i]);
	printf("\n");
}
void firstFit(int mem[], int proc[])
{
	int k=0,i,j; 
	for(i=0; i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if((mem[j]-proc[i])>0)
			{
				mem[j]-=proc[i];
				break;
			}
		}
		if(j==m)
		{
			printf("Process %d cannot be allocated memory",i+1);
			break;
		}
		printMem(mem);
	}
}
void bestFit(int mem[],int proc[])
{
	int k=0,i,j,ind,smallest; 
	for(i=0; i<n;i++)
	{
		ind=-1;
		smallest=INT_MAX;
		for(j=0;j<m;j++)
		{
			if((mem[j]-proc[i])>0)
			{
				if((mem[j]-proc[i])<smallest)
				{
					smallest=(mem[j]-proc[i]);
					ind=j;
				}
			}
		}
		if(ind==-1)
		{
			printf("Process %d cannot be allocated memory",i+1);
			continue;
		}
		else
		{
			mem[ind]-=proc[i];
		}
		printMem(mem);
	}
}
void worstFit(int mem[],int proc[])
{
	int k=0,i,j,ind,largest; 
	for(i=0; i<n;i++)
	{
		ind=-1;
		largest=INT_MIN;
		for(j=0;j<m;j++)
		{
			if((mem[j]-proc[i])>0)
			{
				if((mem[j]-proc[i])>largest)
				{
					largest=(mem[j]-proc[i]);
					ind=j;
				}
			}
		}
		if(ind==-1)
		{
			printf("Process %d cannot be allocated memory",i+1);
			continue;
		}
		else
		{
			mem[ind]-=proc[i];
		}
		printMem(mem);
	}
}
int main()
{
	int mem[10],proc[10];
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	printf("Enter number of memory partition\n");
	scanf("%d",&m);
	printf("Enter sizes of memory partitions\n");
	for(int i=0;i<m;i++)
		scanf("%d", &mem[i]);
	printf("Enter how much memory each process needs \n");
	for(int i=0; i<n;i++)
		scanf("%d",&proc[i]);
	//printf("\n\n FIRST FIT: \n");
	//firstFit(mem, proc);
	// printf("\n\n BEST FIT: \n");
	// bestFit(mem, proc);
	printf("\n\n WORST FIT: \n");
	worstFit(mem, proc);
}

