#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line of input and strip whitespace
char* input() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    // Remove newline character if present
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Function to read an integer from input
int INT() {
    char* line = input();
    return atoi(line);
}

// Function to read a list of integers from input
int* LIST() {
    char* line = input();
    int* arr = NULL;
    char* token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        arr = realloc(arr, (count + 1) * sizeof(int));
        arr[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    arr = realloc(arr, count * sizeof(int));
    return arr;
}

// Function to read multiple lists of integers and return them as tuples
void ZIP(int n, int** output) {
    for (int i = 0; i < n; i++) {
        output[i] = LIST();
    }
}

// Main function
int main() {
    // Read the number of elements
    int N = INT();

    // Read the list of integers
    int* A = LIST();

    // Remove consecutive duplicates from the list
    int* temp = (int*)malloc(N * sizeof(int));
    int temp_size = 0;
    for (int i = 0; i < N; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < temp_size; j++) {
            if (A[i] == temp[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            temp[temp_size++] = A[i];
        }
    }
    free(A);
    A = (int*)malloc(temp_size * sizeof(int));
    memcpy(A, temp, temp_size * sizeof(int));
    free(temp);
    N = temp_size;

    // Initialize the index and answer counter
    int i = 1;
    int ans = 0;

    // Loop through the list to count the number of peaks and valleys
    while (i < N - 1) {
        // Check if the current element is a peak or a valley
        if (A[i - 1] < A[i] && A[i] > A[i + 1] || A[i - 1] > A[i] && A[i] < A[i + 1]) {
            ans += 1;  // Increment the answer for each peak/valley found
            i += 1;    // Skip the next element to avoid double counting
        }
        i += 1;  // Move to the next element
    }

    // Print the total count of peaks and valleys plus one
    printf("%d\n", ans + 1);

    // Free allocated memory
    free(A);
    return 0;
}
