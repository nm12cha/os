//slip no 11 Q1
#include<stdio.h>
void main()
{
     int n,i,p[10],r,a[10][10],j,max[10][10],av[10],need[10][10];
     char res;
     printf("Enter the No. of Processes : ");
     scanf("%d",&n);
     printf("\nEnter the No. of Resources : ");
     scanf("%d",&r);
     printf("Enter the Allocation Matrix : ");
     for (i=0;i<n;i++)
         for (j=0;j<r;j++)
             scanf("%d",&a[i][j]);
     
     printf("\n Enter Max Allocation Matrix : ");
     for (i=0;i<n;i++)
         for (j=0;j<r;j++)
             scanf("%d",&max[i][j]);
     
     printf("\n Enter Available : ");
     for (i=0;i<r;i++)
         scanf("%d",&av[i]);
     printf("\nAllocation Matrix : ");
     for (i=0;i<n;i++)
     {
         printf("\n");
         for (j=0;j<r;j++)
             printf("%d\t",a[i][j]);
     }
     printf("\n Max Allocation Matrix");
    for ( i=0;i<n;i++)
    {
        printf("\np%d\t",i);
        for(j=0;j<r;j++)
            printf("%d\t",max[i][j]);
    }
     printf("\nNeed : ");
     for (i=0;i<n;i++)
     {
         printf("\n%d\t",i);
         for (j=0;j<r;j++)
         {
             need[i][j]=max[i][j]-a[i][j];
             printf("%d\t",need[i][j]);
         }
     }
     printf("\n Available : ");
     for (i=0;i<n;i++)
         if (i==0)
            for (j=0;j<r;j++)
                printf("%d\t",av[j]);
}

/*
slip no 11 Q2
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc,char *argv[])
{
  MPI_Init(&argc,&argv);
  int rank,size;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  
  int *randomNumbers=(int*)malloc(1000*sizeof(int));
  for(int i=0; i<100; i++)
  {
    randomNumbers[i]=rand()%1000;
  }
  int localMin=randomNumbers[0]
  
  for(int i=1; i<100; i++)
  {
    if(randomNumbers[i] < localMin)
    {
      localMin=randomNumbers[i];
    }
  }
  int globalMin,globalMax;
  MPI_Reduce(&localMin,&globalMin,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
 if(rank==0)
  {
    printf("Minimum number:%d\n",globalMin);
  }  
  free(randomNumbers);
  MPI_Finalize();
  return 0;
}        
*/
