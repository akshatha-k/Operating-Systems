#include <stdio.h>
#include <stdlib.h>
void sec(int pr[],int f,int n)
{
	int i,j,ph=0,pf=0,flag=0,done,last=-1;
	int *pframe=(int*)malloc(sizeof(int)*f);
	int *ref=(int*)malloc(sizeof(int)*f);
	for(i= 0;i<n;i++)
	{
		done=0;
		while(!done)
		{
			for(j=last+1; j<f;j++)
			{
				if(pframe[j]== pr[i]){
					ph++;
					ref[j]=1;
					last=j;
					flag=1;
					done=1;
					break;
				}
				else if(ref[j]==1)
					ref[j]=0;
				if(ref==0)
				{
					done=1;
					pframe[j]=pr[i];
					ref[j]=1;
					flag=1;
					last=j;
					done=1;
					break;
				}
			}
			if(flag==0 && !done && j==f)
			{
				for(j=0; j<f;j++)
				{
					if(pframe[j]== pr[i]){
						ph++;
						ref[j]=1;
						last=j;
						flag=1;
						break;
					}
					else if(ref[j]==1)
						ref[j]=0;
					if(ref==0)
					{
						done=1;
						pframe[j]=pr[i];
						ref[j]=1;
						flag=1;
						last=j;
						break;
					}
				}
			}
		
		}
		}
		
		flag=0;
		 printf("\nframes:");
		for(int k=0; k<f;k++){
			printf("%d  ",pframe[k]);
			printf("R:%d ",ref[k]);
		}
		printf("\n");

	printf("\nNumber of page faults : %d \n",pf);
	printf("\nNumber of page hits: %d \n \n",ph);
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
	sec(pr,f,n);
}