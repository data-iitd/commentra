#include <stdio.h>
#include <math.h>

int main() {
    int N;
    
    // Step 1: Read an integer input N which represents some quantity or value.
    scanf("%d", &N);
    
    int A[5];
    
    // Step 2: Read five integer inputs and store them in an array A.
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }
    
    // Step 3: Find the minimum value in the array A.
    int min_value = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] < min_value) {
            min_value = A[i];
        }
    }
    
    // Step 4: Calculate the result and print it.
    int result = (int)ceil((double)N / min_value) + 4;
    printf("%d\n", result);
    
    return 0;
}

// <END-OF-CODE>
