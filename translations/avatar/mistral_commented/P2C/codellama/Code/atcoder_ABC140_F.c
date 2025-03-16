#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from standard input
int* LI() {
    int* S = (int*)malloc(sizeof(int) * I());
    for (int i = 0; i < I(); i++) {
        scanf("%d", &S[i]);
    }
    return S;
}

// Function to sort a list of integers in descending order
void sort(int* S, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (S[i] < S[j]) {
                int temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }
}

// Function to check if a list of integers is sorted in descending order
int isSorted(int* S, int N) {
    for (int i = 0; i < N - 1; i++) {
        if (S[i] < S[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a list of integers is a subsequence of another list of integers
int isSubsequence(int* S, int* T, int N) {
    int i = 0;
    for (int j = 0; j < N; j++) {
        if (S[i] == T[j]) {
            i++;
        }
        if (i == N) {
            return 1;
        }
    }
    return 0;
}

// Function to solve the problem
int main() {
    // Read the number of test cases
    int N = I();

    // Read the list of integers and sort it in descending order
    int* S = LI();
    sort(S, N);

    // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    int* flag = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }

    // Initialize an empty list to store the current subsequence
    int* cur = (int*)malloc(sizeof(int) * N);
    int j = 0;

    // Start from the first integer and include it in the subsequence
    cur[0] = S[0];
    flag[0] = 0;

    // For each integer in the sorted list
    for (int i = 1; i < N; i++) {
        // Initialize variables
        int jM = j;

        // Try to include the current integer in the subsequence
        for (int k = 0; k < N; k++) {
            // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if (flag[k] && S[k] < cur[j - 1]) {
                // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur[j] = S[k];
                j++;
                flag[k] = 0;
                // If the length of the subsequence hasn't changed, break the loop
                if (j == jM) {
                    break;
                }
            }
        }

        // If we couldn't include any integer in the subsequence after the current one, return "No"
        if (j == jM) {
            printf("No\n");
            return 0;
        }

        // Sort the subsequence in descending order
        sort(cur, j + 1);

        // If the subsequence is not sorted in descending order, return "No"
        if (!isSorted(cur, j + 1)) {
            printf("No\n");
            return 0;
        }

        // If the subsequence is not a subsequence of the original list, return "No"
        if (!isSubsequence(cur, S, j + 1)) {
            printf("No\n");
            return 0;
        }
    }

    // If we could include all the integers in the subsequence, return "Yes"
    printf("Yes\n");
    return 0;
}

// 