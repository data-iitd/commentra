#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read n integers from standard input
int* nextInts(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt();
    }
    return arr;
}

// Function to print a single integer to standard output
void puts(int a) {
    printf("%d\n", a);
}

int main() {
    // Initialize the number of elements
    int n = nextInt();
    int* a = nextInts(n);

    // Initialize answer variable
    int ans = 0;

    // Iterate through the array 'a'
    for (int i = 0; i < n; i++) {
        // Initialize left and right indices
        int l = i, r = i + 1;

        // Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }

        // Increment the answer variable
        ans++;

        // Update the index 'i' to 'r' for the next iteration
        i = r;
    }

    // Print the answer
    puts(ans);

    // Free allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
