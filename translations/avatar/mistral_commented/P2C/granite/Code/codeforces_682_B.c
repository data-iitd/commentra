
#include <stdio.h>
#include <stdlib.h>

// Function to read a list of integers from standard input
int* I(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read an integer from standard input
int IS() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read an integer from standard input and convert it to an integer
int IN() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a float from standard input
float IF() {
    float num;
    scanf("%f", &num);
    return num;
}

int main() {
    // Read the number of test cases 'n'
    int n = IN();

    // Read the list 'l' of length 'n' containing 'n' integers
    int* l = I(n);

    // Initialize variable 'f' to 1
    int f = 1;

    // Sort the list 'l' in ascending order
    qsort(l, n, sizeof(int));

    // Initialize variable 'c' to 0
    int c = 0;

    // Iterate through the list 'l'
    for (int i = 0; i < n; i++) {
        // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
        if (l[i] > c) {
            c++;
        }
    }

    // Print the final result, which is the number of unique elements in the list 'l' plus 1
    printf("%d\n", c + 1);

    // Free the memory allocated for the array 'l'
    free(l);

    return 0;
}
