
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
    int* S = malloc(sizeof(int) * I());
    for (int i = 0; i < I(); i++) {
        scanf("%d", &S[i]);
    }
    return S;
}

int main() {
    // Read the number of elements N
    int N = I();
    
    // Read the list of integers S, sort them in descending order
    int* S = LI();
    qsort(S, N, sizeof(int), compare);
    
    // Initialize a flag array to keep track of used elements
    int* flag = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }
    
    // Initialize the current list with the first element of S
    int* cur = malloc(sizeof(int) * N);
    cur[0] = S[0];
    flag[0] = 0;
    
    // Loop through N times
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = i + 1;
        
        // Iterate over the elements of S
        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to False, and increment j
                cur[j + 1] = S[k];
                j++;
                flag[k] = 0;
                if (j == jM) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        if (j == 0) {
            printf("No\n");
            return 0;
        }
        
        // Sort cur in descending order
        qsort(cur, j + 1, sizeof(int), compare);
    }
    
    // Return "Yes" if the condition is satisfied
    printf("Yes\n");
    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

// 