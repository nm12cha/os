//slip no 8 Q1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bv[50],i,st,j,len,c,k;
char name[10][30];
int start[10],length[10],num=0;

void displayBitVector()
{
     printf("\nBit Vector contents :\n");
     for (i=0;i<50;i++)
          printf("%d ",bv[i]);
}
void createFile()
{
     char temp[30];
     printf("Enter the name of file : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
          if (strcmp(name[i],temp)==0)
          {
              printf("\nFilename already exists");
              return;
          } 
     strcpy(name[num],temp);
     printf("Enter the start block of the file : ");
     scanf("%d",&start[num]);
     printf("Enter the length of the file : ");
     scanf("%d",&length[num]);
     
     for (j=start[num];j<(start[num]+length[num]);j++)
          if (bv[j]==0)
          {
              printf("File cannot be allocated.... block already allocated");
              strcpy(name[j],"-");
              start[j]=0;
              length[j]=0;
              return;
          }
     for (j=start[num];j<(start[num]+length[num]);j++)
     {
          bv[j]=0;
          printf("\n%d->%d",j,bv[j]);
     }
     num++;
}
void showDirectory()
{
      printf("Directory contents\n");
      printf("%s%s%s\n","File Name","Start Block","Length");
      int i;
      for (i=0;i<num;i++)
      {
           if (strcmp(name[i],"-")!=0)
           {
               printf("  %s    %d   %d\n",name[i],start[i],length[i]);
           }
      }
}
void deleteFile()
{
     char temp[10];
     printf("\nEnter the filename : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
     {
          if (strcmp(name[i],temp)==0)
          {
             
                   for (j=start[i];j<(start[i]+length[i]);j++)
                   {
                        bv[j]=1;
                        printf("\n%d->%d",j,bv[j]);
                   }
                   printf("\nFile successfully deleted...");
                   strcpy(name[i],"-");
                   start[i]=1;
                   length[i]=1;
                   return;           
          }
     }
}
int main()
{
    int ch=0;
    for (i=0;i<50;i++)
         bv[i]=1;
         
    do 
    {
        printf("\n---Select One Of The Option----\n");
        printf("\n1.Show bit Vector :");
        printf("\n2.Create New File :");
        printf("\n3.Show Directory :");
        printf("\n4.Delete File :");
        printf("\n5.Exit:\n");
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);
        
        switch (ch)
        {
                case 1: displayBitVector();
                        break;
                case 2: createFile();
                        break;
                case 3: showDirectory();
                        break;
                case 4: deleteFile();
                        break;
        }
    }
    while(ch!=5);
}

/*
slip no 8 Q2
#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,n,init,total=0,minD,index,temp,dist,j;
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
          minD = abs(req[i]-init);
          index = i;
          for (j=i+1;j<n;j++)
          {
              dist = abs(req[j]-init);
              if (dist<=minD)
              {
                 minD = dist;
                 index = j;
              }
          }
          total+=minD;
          temp=req[i];
          req[i]=req[index];
          req[index]=temp;
          init=req[i];
     }
     printf("total head movements : %d",total);          
}
*/