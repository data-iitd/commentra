#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare an integer to hold the number of elements
    int n;
    // Read the number of elements from user input
    scanf("%d", &n);

    // Declare an integer to hold the number of largest elements to sum
    int a;
    // Read the number of largest elements to sum from user input
    scanf("%d", &a);

    // Initialize a variable to hold the sum of the largest elements
    int sum = 0;

    // Declare an array to hold the elements
    int s[n];

    // Read the elements into the array from user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    // Sort the array in non-decreasing order
    qsort(s, n, sizeof(int), compare);

    // Sum the largest 'a' elements from the sorted array
    for (int i = n - 1; i > n - a - 1; i--) {
        sum += s[i];
    }

    // Output the calculated sum of the largest 'a' elements
    printf("%d\n", sum);

    // Return 0 to indicate successful completion of the program
    return 0;
}

