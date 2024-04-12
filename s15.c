//slip no 15 Q1
#include <stdio.h>
#include <stdlib.h>

int bv[50], p, a;
int st, len, k, c, j;
char fnm[20], f[20];

void rec(int bv[], int, int);

int main()
{

    FILE *fp;
    int len;
    int t;
    int op = 1;

    printf("\n Enter Total Block : ");
    scanf("%d", &t);

    bv[t];

    for (int i = 0; i < t; i++)
        bv[i] = 1;

    printf("\n Bit Vector Before Allocation \n ");
    for (int i = 0; i < t; i++)
        printf("%d", bv[i]);

    printf("\n");

    printf("\nEnter the number of blocks already allocated: ");
    scanf("%d", &p);
    printf("\nEnter the blocks already allocated: ");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &a);
        bv[a] = 0;
    }

    printf("\n ");
    while (op >= 1 && op <= 4)
    {

        printf("\n 1.Create File");
        printf("\n 2.Show bit Vector ");
        printf("\n 3.Show Directory  ");
        printf("\n 4.Exit");

        printf("\n Enter option :  ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nEnter File name : ");
            scanf("%s", fnm);

            fp = fopen(fnm, "w");

            if (fp == NULL)
            {
                printf("\nError opening the file.\n");
                return 1;
            }
            else
                printf("\n *** File is created *** \n ");

            printf("Enter the index of the sting block and its length: ");
            scanf("%d%d", &st, &len);
            rec(bv, st, len);
            // fclose(fp);
            break;

        case 2:
            printf("\n Bit Vector After  Allocation \n ");
            for (int i = 0; i < t; i++)
                printf("%d", bv[i]);

            printf("\n");
            break;
        case 3:
            printf("\n File Details Are : \n ");
            printf("\nF_NM\tIB\tLen\n");
            printf("%s\t%d\t%d", fnm, st, len);
            printf("\n");
            break;

        case 4:
            exit(0);
        }
    }

    fclose(fp);
    return 0;
}

void rec(int bv[], int st, int len)
{

    k = len;
    printf("\nFNm\tIndesx\tAllocated\n\n");
    if (bv[st] == 1)
    {
        for (j = st; j < (st + k); j++)
        {
            if (bv[j] == 1)
            {
                bv[j] = 0;
                printf("%s\t%d------->%d\n", fnm, j, bv[j]);
            }
            else
            {
                printf("\nThe block %d is already allocated \n\n", j);
                k++;
            }
        }
    }
    else
        printf("\nThe block %d is already allocated \n\n", st);
}

/*
slip no 15 Q2
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,seek=0,max,head,move,q[100];
	printf("\n Enter queue size:");
	scanf("%d",&n);
	printf("\n Enter queue elements:");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter initial head position:");
	scanf("%d",&head);
	printf("\n Enter max disk size:");
	scanf("%d",&max);
	printf("\n Enter the head movemnet direction 1 for high and 0 foe low:");
	scanf("%d",&move);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(q[j]>q[j+1])
			{
				int temp;
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
		}
	}
	
	int index;
	for(i=0;i<n;i++)
	{
		if(head<q[i])
		{
			index=i;
			break;
		}
	}
	
	printf("\n Sequence of head movement:");
	if(move==1)
	{
		printf("%d\t",head);
		for(i=index;i<n;i++)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
		seek+=abs(max-q[i-1]-1);
		seek+=abs(max-1-0);
		printf("%d\t",max-1);
		head=0;
		printf("%d\t",head);
		for(i=0;i<index;i++)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
	}
	else
	{
		printf("%d\t",head);
		for(i=index-1;i>=0;i--)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
		seek+=abs(q[i+1]-0);
		seek+=abs(max-1-0);
		head=max-1;
		printf("%d\t",head);
		for(i=n-1;i>=index;i--)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
	}
	printf("\n\n Total head movements are %d",seek);
	return 0;
}
*/
