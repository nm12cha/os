//slip no 7 Q1
#include<stdio.h>
int main() 
{   
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int allocation[n][m],max[n][m],need[n][m];
    int available[m],safe_sequence[n],finish[n];

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
            scanf("%d", &max[i][j]);
        }
    }
    for (i = 0; i < n; i++) 
		{
        for (j = 0; j < m; j++) 
				{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Enter the available resources vector:\n");
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
slip no 9 Q2
#include <stdio.h>
#include <stdlib.h>

// Function to sort the disk request array
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the index of the first element greater than or equal to the head
int findIndex(int arr[], int n, int head) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= head) {
            index = i;
            break;
        }
    }
    return index;
}

// Function to simulate LOOK disk scheduling algorithm
void look(int arr[], int n, int head) {
    int total_head_movements = 0;

    // Sort the disk request array
    sort(arr, n);

    // Find the index of the first element greater than or equal to the head
    int index = findIndex(arr, n, head);

    // If no element is found greater than or equal to head, move to the last request
    if (index == -1) {
        index = n - 1;
        printf("%d -> ", head);
        total_head_movements += abs(head - arr[index]);
        head = arr[index];
    }

    // Move right
    for (int i = index; i < n; i++) {
        printf("%d -> ", arr[i]);
        total_head_movements += abs(head - arr[i]);
        head = arr[i];
    }

    // Move left
    for (int i = index - 1; i >= 0; i--) {
        printf("%d -> ", arr[i]);
        total_head_movements += abs(head - arr[i]);
        head = arr[i];
    }

    printf("\nTotal head movements: %d\n", total_head_movements);
}

int main() {
    int num_blocks, head_position;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &num_blocks);

    int *request_queue = (int *)malloc(num_blocks * sizeof(int));

    if (request_queue == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the disk request string: ");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &head_position);

    printf("Order of service:\n");
    look(request_queue, num_blocks, head_position);

    free(request_queue);

    return 0;
}

*/