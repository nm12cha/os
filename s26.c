//slip no 26 Q1
#include<stdio.h>
int main() 
{    
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m], safe_sequence[n], finish[n];    
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++) 
        {
          scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++) 
        {
          scanf("%d",&max[i][j]);
        }
    }
    printf("\nNeed :");
    for (i = 0; i < n; i++) 
    {
        printf("\n p%d \t",i);
        for (j = 0; j < m; j++) 
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d\t ",need[i][j]);
        }
    }
    printf("\nEnter the available resources vector:\n");
    for (i = 0; i < m; i++) 
    {
        scanf("%d", &available[i]);
    }
    for (i = 0; i < n; i++) 
    {
        finish[i] = 0;
    }
    int count = 0;
    while (count < n) 
    {
        int found = 0;
        for (i = 0; i < n; i++) 
        {
            if (finish[i] == 0) 
            {
                int safe = 1;
                for (j = 0; j < m; j++) 
                {
                    if (need[i][j] > available[j]) 
                    {
                        safe = 0;
                        break;
                    }
                }
               if (safe == 1) 
               {
                    safe_sequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                    for (j = 0; j < m; j++) 
                    {
                        available[j] += allocation[i][j];
                    }
               }
            }
        }
        if (found == 0) 
        {
          printf("System is in unsafe state.\n");
          return 0;
        }
    }
     printf("Safe sequence is: ");
     for (i = 0; i < n; i++) 
     {
        printf("%d ", safe_sequence[i]);
     }
     printf("\n");
     return 0;
}

/*
slip no 26 Q2
#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,n,init,total=0;
     printf("Enter no. of disk req. : ");
     scanf("%d",&n);
     int req[n];
     printf("Enter disk req queue : ");
     for (i=0;i<n;i++)
          scanf("%d",&req[i]);
     printf("enter initial head position : ");
     scanf("%d",&init);
     for (i=0;i<n;i++)
     {
          total+=abs(req[i]-init);
          init=req[i];
     }
     printf("total head movements : %d",total);          
}
*/
