#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from input
int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

<<<<<<< HEAD
// Function to reverse a segment of an array in place
=======
// Function to reverse a segment of the array in place
>>>>>>> 98c87cb78a (data updated)
void reva(int *b, int start, int end) {
    while (start < end) {
        int temp = b[start];
        b[start] = b[end];
        b[end] = temp;
        start++;
        end--;
    }
}

// Main function
int main() {
    int n = nextInt(); // Reads the number of elements
    int *a = (int *)malloc(n * sizeof(int)); // Allocates memory for the array
    for (int i = 0; i < n; i++) {
        a[i] = nextInt(); // Reads each element and assigns it to the array
    }
    
    int q = nextInt(); // Reads the number of queries
    for (int i = 0; i < q; i++) {
        int b = nextInt(); // Reads the start index of the segment to reverse
        int e = nextInt(); // Reads the end index of the segment to reverse
        reva(a, b, e - 1); // Reverses the segment of the array
    }
    
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // Adds a space between elements, except before the first element
        }
        printf("%d", a[i]); // Prints the element
    }
    printf("\n"); // Adds a newline after all elements
    
    free(a); // Frees the allocated memory
    return 0; // Returns 0 to indicate successful execution
}

// <END-OF-CODE>
