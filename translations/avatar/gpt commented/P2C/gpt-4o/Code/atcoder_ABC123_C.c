#include <stdio.h>
#include <math.h>

int main() {
    // Read an integer input from the user
    int N;
    scanf("%d", &N);

    // Read 5 integer inputs from the user and store them in an array A
    int A[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the minimum value from the array A
    int min_value = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] < min_value) {
            min_value = A[i];
        }
    }

    // Calculate the result and print it
    printf("%d\n", (int)ceil((double)N / min_value) + 4);

    return 0;
}

// <END-OF-CODE>
