#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a list of integers from standard input
void readList(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to compare integers for qsort in descending order
int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Main function to solve the problem
char* main() {
    // Read the number of test cases
    int N = readInt();

    // Read the list of integers and sort it in descending order
    int S[N];
    readList(S, N);
    qsort(S, N, sizeof(int), compareDesc);

    // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    int flag[N];
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }

    // Initialize an empty list to store the current subsequence
    int cur[N];
    cur[0] = S[0];
    flag[0] = 0;

    // For each integer in the sorted list
    for (int i = 0; i < N; i++) {
        // Initialize variables
        int j = 0;
        int jM = 1; // jM is always 1 initially because cur[0] is already included

        // Try to include the current integer in the subsequence
        for (int k = 0; k < N; k++) {
            // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if (flag[k] && S[k] < cur[j]) {
                // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur[jM] = S[k];
                jM++;
                flag[k] = 0;
                // If the length of the subsequence hasn't changed, break the loop
                if (jM == j + 1) {
                    break;
                }
            }
        }

        // If we couldn't include any integer in the subsequence after the current one, return "No"
        if (jM == 1) {
            char* no = (char*)malloc(3 * sizeof(char));
            no[0] = 'N';
            no[1] = 'o';
            no[2] = '\0';
            return no;
        }

        // Sort the subsequence in descending order
        qsort(cur, jM, sizeof(int), compareDesc);
    }

    // If we could include all the integers in the subsequence, return "Yes"
    char* yes = (char*)malloc(3 * sizeof(char));
    yes[0] = 'Y';
    yes[1] = 'e';
    yes[2] = 's';
    yes[3] = '\0';
    return yes;
}

// Run the main function if the script is executed directly
int main() {
    // Read the output and print it
    char* result = main();
    printf("%s\n", result);
    free(result);
    return 0;
}
