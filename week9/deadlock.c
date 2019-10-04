#include<stdio.h>
int main()
{
  int n1,n2;
  printf("Enter no of processes and resources: ");
  scanf("%d %d", &n1, &n2);

  int request[n1][n2], alctd[n1][n2], avlbl[n2],work[n2] ,check[n2],w=0,flag=0,c=0;
        int finish[n1];
  printf("\nEnter request \n");
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
      scanf("%d", &request[i][j]);
    }
    printf("\nEnter allocated \n");
    for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
    {
      scanf("%d", &alctd[i][j]);
    }
  }
  printf("\nEnter resource available for each resource: ");
  for(int i=0;i<n2;i++)
  {
    scanf("%d", &avlbl[i]);
  }
  for(int i=0;i<n1;i++)
        {
         finish[i]=0;
        }
        for(int i=0;i<n2;i++)
           check[i]=avlbl[i];

        for(int i=0;i<n1;i++)
          for(int j=0;j<n2;j++)
                 {
                   check[j]=check[j]+alctd[i][j];
                 }

        for(int i=0;i<n2;i++)
         work[i]=avlbl[i];
        for(int i=0;i<n1;i++)
  { w=0;
          for(int j=0;j<n2;j++)
    { if(alctd[i][j]==0)
                     w=w+1;
                 }
          if(w==n2)
          {
           finish[i]=1;
          }
  }
        end:
        for(int i=0;i<n1;i++)
  {
          if(finish[i]==0)
          {
            flag=0;
             for(int j=0;j<n2;j++)
    {
                  if(request[i][j]>work[j])
                    {
                      flag=1;
                      break;
                    }
                }
            if(flag==0)
             {
               for(int j=0;j<n2;j++)
                 {
                   work[j]=work[j]+alctd[i][j];
                 }
              finish[i]=1;
              goto end;
       }

          }
        }

        flag=0;
        for(int j=0;j<n2;j++)
          if(check[j]!=work[j])
            flag=1;

         if(flag==0)
          printf("\nno deadlock detected");
         else
          {printf("\ndeadlock detected");
          }
  return 0;
}
