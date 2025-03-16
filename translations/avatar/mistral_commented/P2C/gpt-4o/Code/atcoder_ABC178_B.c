#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Main function
int main() {
    // Read input values
    int a = readInt();
    int b = readInt();
    int c = readInt();
    int d = readInt();

    // Calculate the maximum product of pairs of numbers
    long long result = (long long)a * c;
    long long temp;

    temp = (long long)b * d;
    if (temp > result) result = temp;

    temp = (long long)a * d;
    if (temp > result) result = temp;

    temp = (long long)b * c;
    if (temp > result) result = temp;

    // Print the result
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
