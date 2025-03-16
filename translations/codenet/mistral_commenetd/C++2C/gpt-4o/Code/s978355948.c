#include <stdio.h>

int main() {
    // Initialize variables N and X with user input
    int N, X;
    scanf("%d %d", &N, &X);

    // Create an array L of size N to store the elements
    int L[N];

    // Read elements of array L from user input
    for(int i = 0; i < N; i++)
        scanf("%d", &L[i]);

    // Initialize variable i and d to zero
    int i = 0, d = 0;

    // Loop through the array L until the sum d exceeds X
    for(; i < N && d <= X; i++) {
        // Add the current element of array L to the sum d
        d += L[i];
    }

    // Print the index of the last element in the array L that was added to the sum d
    printf("%d\n", i + 1);

    return 0;
}

// <END-OF-CODE>
