#include<stdio.h>
#include<stdlib.h>
int n,m;
int safety(int avail[], int alloc[n][m], int need[n][m])
{
	int work[m];
	for(int i=0;i<m;i++)
	{
		work[i]=avail[i];
	}
	int finish[n];
	for(int i=0;i<n;i++)
	{
		finish[i]=0;
	}
	int comp=1;
	int count=n*n;
	int i =0;
	int cond=0;
    printf("sequence \n");
	while(count>0)
	{
		if(finish[i]==0)
		{
			for(int j=0;j<m;j++)
				if(need[i][j]>work[j])
			{
				cond=1;
				break;
			}
			if(cond==0)
			{
				for(int j=0;j<m;j++)
				{
					work[j]+=alloc[i][j];
				}
				finish[i]=comp++;
			}
		}
		count--;
		i++;
		if(i==n)
			i=0;
		cond=0;
	}
	for(int i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
			cond=1;
			break;
		}
        printf("%d ",finish[i]);
	}
	return cond;
}

int main()
{
	printf("Enter processes and resources \n");
	scanf("%d %d",&n,&m);
	int max[n][m], alloc[n][m], avail[m], need[n][m];

	printf("Enter max \n");
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter allocated \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j]-alloc[i][j];
        }
    }
    printf("Enter rem avail \n");
    for(int i=0;i<m;i++)
    {
        scanf("%d", &avail[i]);
    }
    printf("Need\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",abs(need[i][j]));
        }
        printf("\n");
    }
    int x = safety(avail, alloc, need);
    if(x==0)
        printf("\nSafe\n");
    else
        printf("\nUnsafe\n");

    int cont=1;
    int pro=0, req[m], flag=0;
    if(x==0)
    {
        while(cont == 1)
        {
            printf("enter process to request for\n");
            scanf("%d",&pro);
            printf("enter the needed resorce vector\n");
            for(int j=0;j<m;j++)
                    scanf("%d", &req[j]);

            for(int j=0;j<m;j++)
            {
                if(req[j]>need[pro][j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("greater than max  \n");
      			goto end;
            }
            flag=0;

            for(int j=0;j<m;j++)
            {
                if(req[j]>avail[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                printf("Waiting for other processes to finish \n");
                goto end;
            }

            for(int j=0;j<m;j++)
            {
                avail[j]-=req[j];
                alloc[pro][j]+=req[j];
                need[pro][j]-=req[j];
            }

            int x = safety(avail, alloc, need);
            if(x==0)
                printf("Request granted\n");
            else
            {
                printf("Request rejected\n");
                for(int j=0;j<m;j++)
                {
                    avail[j]+=req[j];
                    alloc[pro][j]-=req[j];
                    need[pro][j]+=req[j];
                }
            }
            end:
            printf("enter 1 to continue \n");
            scanf("%d", &cont);
        }
	}
    return 0;
}
