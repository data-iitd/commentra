#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to read an integer from standard input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from standard input
void LI(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

// Main function to solve the problem
const char* main_function() {
    // Read the number of test cases
    int N = I();

    // Read the list of integers
    int S[MAX_SIZE];
    LI(S, N);

    // Sort the list in descending order
    qsort(S, N, sizeof(int), compare);

    // Initialize a flag array to keep track of included integers
    int flag[MAX_SIZE] = {1}; // 1 means included, 0 means not included

    // Initialize an empty list to store the current subsequence
    int cur[MAX_SIZE];
    int cur_size = 0;

    // Start from the first integer and include it in the subsequence
    cur[cur_size++] = S[0];
    flag[0] = 0; // Mark as included

    // For each integer in the sorted list
    for (int i = 1; i < N; i++) {
        // Initialize variables
        int j = 0;
        int jM = cur_size;

        // Try to include the current integer in the subsequence
        for (int k = 0; k < N; k++) {
            // If the flag of the current integer is 1 and it is smaller than the last integer in the subsequence
            if (flag[k] && S[k] < cur[j]) {
                // Include the current integer in the subsequence
                cur[cur_size++] = S[k];
                j++;
                flag[k] = 0; // Mark as included
                // If the length of the subsequence hasn't changed, break the loop
                if (j == jM) {
                    break;
                }
            }
        }

        // If we couldn't include any integer in the subsequence after the current one, return "No"
        if (j == jM) {
            return "No";
        }

        // Sort the subsequence in descending order
        qsort(cur, cur_size, sizeof(int), compare);
    }

    // If we could include all the integers in the subsequence, return "Yes"
    return "Yes";
}

// Run the main function if the script is executed directly
int main() {
    // Read the output and print it
    printf("%s\n", main_function());
    return 0;
}

// <END-OF-CODE>
