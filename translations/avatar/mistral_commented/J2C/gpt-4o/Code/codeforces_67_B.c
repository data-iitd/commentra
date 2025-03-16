#include <stdio.h>  // Including standard input/output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

// Function to read integers from standard input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int n = readInt();  // Reading the number of elements in the array 'bb'
    int k = readInt();  // Reading the value of 'k'
    
    int *bb = (int *)malloc(n * sizeof(int));  // Dynamically allocating an integer array 'bb' of size 'n'
    for (int i = 0; i < n; i++) {
        bb[i] = readInt();  // Reading each element of the array 'bb'
    }

    int *aa = (int *)malloc(n * sizeof(int));  // Dynamically allocating an integer array 'aa' of size 'n'
    int m = 0;  // Initializing an integer variable 'm' to keep track of the index of the last element added to 'aa'

    for (int a = n - 1; a >= 0; a--) {  // Iterating through the array 'bb' from the last index to the first index
        int j = 0;
        while (bb[a] > 0) {  // While there are still elements in 'bb' at index 'a' to be processed
            if (aa[j] >= a + k) {  // Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
                bb[a]--;  // If true, decrement the number of elements in 'bb' at index 'a'
            }
            j++;  // Incrementing j
        }

        // Shifting elements in 'aa' to make space for the new element
        for (int j_ = m; j_ > j; j_--) {  // Iterating through the array 'aa' from the last index added to the current index 'j'
            aa[j_] = aa[j_ - 1];  // Swapping the elements at indices 'j_' and 'j_ - 1'
        }

        aa[j] = a;  // Adding the current index 'a' to the array 'aa' at index 'j'
        m++;  // Incrementing m to reflect the new size of 'aa'
    }

    for (int i = 0; i < n; i++) {  // Iterating through the array 'aa' and printing each element
        printf("%d ", aa[i] + 1);  // Printing the index (1-based)
    }

    printf("\n");  // Printing a newline character

    // Freeing dynamically allocated memory
    free(bb);
    free(aa);

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
