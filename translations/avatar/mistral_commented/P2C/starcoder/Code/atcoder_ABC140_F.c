#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int I() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a list of integers from standard input
int* LI() {
    int n = I();
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to print a list of integers to standard output
void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort a list of integers in descending order
void sortArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to find the longest increasing subsequence
int findLIS(int* arr, int n) {
    // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    int* flag = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        flag[i] = 1;
    }

    // Initialize an empty list to store the current subsequence
    int* cur = (int*) malloc(n * sizeof(int));

    // Start from the first integer and include it in the subsequence
    cur[0] = arr[0];
    flag[0] = 0;

    // For each integer in the sorted list
    for (int i = 1; i < n; i++) {
        // Initialize variables
        int j = 0;
        int jM = i;

        // Try to include the current integer in the subsequence
        for (int k = 0; k < n; k++) {
            // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if (flag[k] && arr[k] < cur[j]) {
                // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur[j + 1] = arr[k];
                j += 1;
                flag[k] = 0;
                // If the length of the subsequence hasn't changed, break the loop
                if (j == jM) {
                    break;
                }
            }
        }
    }

    // Return the length of the longest increasing subsequence
    return j + 1;
}

// Main function to solve the problem
int main() {
    // Read the number of test cases
    int N = I();

    // Read the list of integers and sort it in descending order
    int* S = LI();
    sortArr(S, N);

    // Find the longest increasing subsequence
    int LIS = findLIS(S, N);

    // If the length of the longest increasing subsequence is equal to the number of integers, return "Yes"
    if (LIS == N) {
        printf("Yes\n");
    }
    // Otherwise, return "No"
    else {
        printf("No\n");
    }

    // Free the memory allocated to the list of integers
    free(S);

    // Return from the main function
    return 0;
}

