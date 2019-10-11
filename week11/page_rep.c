#include <stdio.h>
#include <stdlib.h>

void fifo(int pr[], int f,int n)
{
	int pf=0,ph=0,c=-1,flag;
	int *pframe=(int*)malloc(sizeof(int)*f);
	for(int j=0; j<f;j++)
	{
		pframe[j]=-1;

	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0; j<f;j++)
		{
			if(pframe[j]== pr[i]){
				ph++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		pf++;
		pframe[(c+1)%f]=pr[i];
		c=(c+1)%f;
		}
		flag=0;
	}
	printf("\nNumber of page faults in FIFO: %d \n",pf);
	printf("\nNumber of page hits in FIFO: %d \n \n",ph);
}
void optimal(int pr[], int f,int n)
{
	int i,j,ph=0,pf=0,flag=0;
	int *pframe=(int*)malloc(sizeof(int)*f);
	int *count=(int*)malloc(sizeof(int)*f);
	for(j=0; j<f;j++)
	{
		pframe[j]=-1;

	}
	for(i= 0;i<n;i++)
	{
		for(j=0; j<f;j++)
		{
			if(pframe[j]== pr[i]){
				ph++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			pf++;
			for(int k=0;k<f;k++)
			{
				count[k]=n;
				for(j=i+1;j<n;j++)
				{
					if(pframe[k]== pr[j])
					{
						count[k]=j;
						break;
					}
				}
			}
			int large=0,ind=0;
			for(j=0;j<f;j++)
			{	
				if(count[j]>large)
				{
					large=count[j];
					ind=j;
				}
			}
			pframe[ind]=pr[i];
		}
		flag=0;
	}
	printf("\nNumber of page faults in Optimal: %d \n",pf);
	printf("\nNumber of page hits in Optimal: %d \n \n",ph);
}
void lru(int pr[], int f,int n)
{
	int i,j,timer=0,ph=0,pf=0,flag=0;
	int *pframe=(int*)malloc(sizeof(int)*f);
	int *time=(int*)malloc(sizeof(int)*f);
	for(j=0; j<f;j++)
	{
		pframe[j]=-1;

	}
	for(i= 0;i<n;i++)
	{
		timer++;
		for(j=0; j<f;j++)
		{
			if(pframe[j]== pr[i]){
				ph++;
				flag=1;
				time[j]=timer;
				break;
			}
		}
		if(flag==0)
		{
			pf++;
			int small=999,ind=0;
			for(j=0;j<f;j++)
			{	
				if(time[j]<small)
				{
					small=time[j];
					ind=j;
				}
			}
			pframe[ind]=pr[i];
			time[ind]=timer;
		}
		// printf("\nframes:");
		// for(int k=0; k<f;k++)
		// 	printf("%d",pframe[k]);
		// printf("\n");
		flag=0;
	}
	printf("\nNumber of page faults in LRU: %d \n",pf);
	printf("\nNumber of page hits in LRU: %d \n \n",ph);
}
int main()
{
	int f,n,pr[20];
	printf("\nEnter the number of frames : ");
	scanf("%d",&f);
	printf("\nEnter the size of the page reference string : ");
	scanf("%d", &n);
	printf("\nEnter the page requests : ");
	for(int i=0;i<n;i++)
		scanf("%d",&pr[i]);
	fifo(pr,f,n);
	lru(pr,f,n);
	optimal(pr,f,n);
}

// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1