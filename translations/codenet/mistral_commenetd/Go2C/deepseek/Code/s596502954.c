#include <stdio.h>
#include <stdlib.h>

// Function to read a single word as a string from the input
char* next() {
    char* buffer = (char*)malloc(100 * sizeof(char));
    scanf("%s", buffer);
    return buffer;
}

// Function to read an integer from the input
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a float64 from the input
double nextFloat64() {
    double num;
    scanf("%lf", &num);
    return num;
}

// Function to read n integers from the input and return as a slice
int* nextInts(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        slice[i] = nextInt();
    }
    return slice;
}

// Main function
int main() {
    // Read the first three integers from the input
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    // Check if the condition is true
    if (a + b >= c) {
        // If true, print "Yes" to the output
        printf("Yes\n");
    } else {
        // If false, print "No" to the output
        printf("No\n");
    }

    // End of code <END-OF-CODE>