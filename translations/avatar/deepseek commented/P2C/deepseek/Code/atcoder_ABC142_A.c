#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from input
int next_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read multiple integers from input and store them in an array
int* next_ints() {
    int* arr = (int*)malloc(1000 * sizeof(int)); // Assuming the input won't exceed 1000 integers
    char ch;
    int i = 0;
    while (scanf("%d%c", &arr[i], &ch) == 2) {
        if (ch == '\n') break;
        i++;
    }
    return arr;
}

int main() {
    // Read the value of n from input
    int n = next_int();

    // Initialize a counter to keep track of odd numbers
    int t = 0;

    // Loop through each number from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if the current index plus one is odd
        if ((i + 1) % 2 != 0) {
            // Increment the counter if the condition is true
            t++;
        }
    }

    // Calculate the ratio of odd numbers to the total numbers and print it
    printf("%.10f\n", (double)t / n);

    return 0;
}
