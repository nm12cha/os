//Slip 1 Q1
#include <stdio.h>

#define MAX_RESOURCES 10
#define MAX_PROCESSES 10

int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int num_processes, num_resources;

void acceptAvailable() {
    printf("Enter available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
}

void displayAllocationMax() {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("Max Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
}

void displayNeedMatrix() {
    printf("Need Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

void displayAvailable() {
    printf("Available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        printf("Resource %d: %d\n", i + 1, available[i]);
    }
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation, Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                acceptAvailable();
                break;
            case 2:
                displayAllocationMax();
                break;
            case 3:
                displayNeedMatrix();
                break;
            case 4:
                displayAvailable();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


/*
Slip 1 Q2
#include<stdio.h>
#include<stdlib.h>
void main(){
	int i,n,init,total=0;
	printf("Enter number of disk request : ");
	scanf("%d",&n);
	int req[n];
	printf("Enter disk request queue : ");
	for (i=0;i<n;i++)
		scanf("%d",&req[i]);
	printf("Enter initial head position : ");
	scanf("%d",&init);
	for (i=0;i<n;i++){
		total+=abs(req[i]-init);
		init=req[i];
	}
	printf("Total head movements : %d",total);
}

*/