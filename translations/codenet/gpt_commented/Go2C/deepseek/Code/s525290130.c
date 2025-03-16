#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from the standard input
int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Function to reverse a slice of integers in place
void reva(int* b, int len) {
    for (int i = 0; i < len / 2; i++) {
        int temp = b[i];
        b[i] = b[len - 1 - i];
        b[len - 1 - i] = temp;
    }
}

int main() {
    // Read the number of elements in the array
    int n = nextInt();
    int a[n];

    // Populate the array with integers from input
    for (int i = 0; i < n; i++) {
        a[i] = nextInt();
    }

    // Read the number of queries
    int q = nextInt();
    // Process each query
    for (int i = 0; i < q; i++) {
        int b = nextInt(); // Read the starting index for the reversal
        int e = nextInt(); // Read the ending index for the reversal
        reva(a + b, e - b); // Reverse the slice from index b to e
    }

    // Output the modified array
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // Print a space before each element except the first
        }
        printf("%d", a[i]); // Print the current element
    }
    printf("\n"); // Print a newline after the output

    return 0;
}
