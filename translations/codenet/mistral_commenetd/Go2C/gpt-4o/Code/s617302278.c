// Importing required libraries
#include <stdio.h>
#include <stdlib.h>

// Function to read a line of integers from stdin and return the first integer
int NextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to find the index where the sum of integers is greater than or equal to x
int findIndex(int x) {
    int sum = 0;
    int i = 1;
    while (1) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    return i;
}

// Main function
int main() {
    // Reading the first integer from stdin
    int x = NextInt();
    // Finding the index
    int index = findIndex(x);
    // Printing the index
    printf("%d\n", index);
    return 0;
}

// <END-OF-CODE>
