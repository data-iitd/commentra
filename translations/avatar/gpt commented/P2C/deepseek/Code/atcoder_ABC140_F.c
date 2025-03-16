#include <stdio.h>
#include <stdlib.h>

// Function to read a single integer from standard input
int I() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a list of integers from standard input
int* LI() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to compare integers for qsort in descending order
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Main function
char* main() {
    // Read the number of elements
    int N = I();
    
    // Read the list of integers, sort it in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), compare);
    
    // Initialize a flag list to track which elements have been used
    int* flag = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }
    
    // Initialize the current list with the largest element
    int* cur = (int*)malloc(N * sizeof(int));
    cur[0] = S[0];
    
    // Mark the first element as used
    flag[0] = 0;
    
    // Iterate N times to build the current list
    for (int i = 0; i < N; i++) {
        int j = 0;  // Index for the current list
        int jM = i + 1;  // Length of the current list
        
        // Try to find the next largest unused element
        for (int k = 0; k < N; k++) {
            // Check if the current element is unused and smaller than the last added element
            if (flag[k] && S[k] < cur[j]) {
                cur[j + 1] = S[k];  // Add the element to the current list
                j++;  // Move to the next index in the current list
                flag[k] = 0;  // Mark this element as used
                
                // If we have added enough elements, break out of the loop
                if (j == jM) {
                    break;
                }
            }
        }
        
        if (j != jM) {
            // If we couldn't find a suitable element, return "No"
            char* no = (char*)malloc(3 * sizeof(char));
            no[0] = 'N';
            no[1] = 'o';
            no[2] = '\0';
            return no;
        }
        
        // Sort the current list in descending order for the next iteration
        qsort(cur, j + 1, sizeof(int), compare);
    }
    
    // If we successfully built the list, return "Yes"
    char* yes = (char*)malloc(3 * sizeof(char));
    yes[0] = 'Y';
    yes[1] = 'e';
    yes[2] = 's';
    yes[3] = '\0';
    return yes;
}

// Entry point of the program
int main() {
    // Print the result of the main function
    char* result = main();
    printf("%s\n", result);
    free(result);
    return 0;
}
