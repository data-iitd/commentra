#include <stdio.h>
#include <stdlib.h>

#define SIZE ((int)(1e5 * 2) + 13) // Define the size of the array

int cnt[SIZE] = {0}; // Initialize an array 'cnt' of size 'SIZE' to store the frequency count of each element

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // Comparison function for qsort
}

int main() {
    int n, k; // Declare two integers 'n' and 'k' to read input

    scanf("%d %d", &n, &k); // Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input

    for (int i = 0; i < n; ++i) { // Loop through the input elements
        int x; // Declare an integer 'x' to read an element from the standard input

        scanf("%d", &x); // Read an element 'x' from the standard input

        cnt[x]++; // Increment the frequency count of the element 'x' in the array 'cnt'
    }

    int a[SIZE]; // Initialize an array 'a' to store the frequency counts
    int a_size = 0; // Variable to keep track of the size of 'a'

    for (int i = 0; i < SIZE; ++i) { // Loop through all elements in the array 'cnt'
        if (cnt[i] > 0) // If the frequency count of an element is greater than zero
            a[a_size++] = cnt[i]; // Add the frequency count to the array 'a'
    }

    int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

    qsort(a, a_size, sizeof(int), compare); // Sort the array 'a' in ascending order

    int m = a_size - k; // Calculate the index of the last frequency count to be considered

    for (int i = 0; i < m; ++i) { // Loop through the first 'm' frequency counts and add them to the variable 'ans'
        ans += a[i];
    }

    printf("%d\n", ans); // Print the result 'ans' to the standard output
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
