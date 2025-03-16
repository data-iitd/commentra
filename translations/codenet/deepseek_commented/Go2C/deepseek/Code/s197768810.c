#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a float64 from standard input
double readFloat64() {
    double num;
    scanf("%lf", &num);
    return num;
}

// Function to read a string from standard input
char* readString() {
    char *str = (char*)malloc(100 * sizeof(char)); // Allocate memory for the string
    scanf("%s", str);
    return str;
}

// Main function to execute the program
int main() {
    // Read two integers n and m from the input
    int n = readInt();
    int m = readInt();

    // Initialize an array to hold m integers
    int a[m];
    int sum = 0;

    // Read m integers into the array a and calculate their sum
    for (int i = 0; i < m; i++) {
        a[i] = readInt();
        sum += a[i];
    }

    // Check if the sum of integers exceeds n
    if (sum > n) {
        // Print -1 if the sum exceeds n and exit
        printf("-1\n");
        return 0;
    }

    // Print the difference between n and the sum if it's within bounds
    printf("%d\n", n - sum);

    return 0;
}
