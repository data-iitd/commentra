#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000000 // Define a maximum size for the array
long long l[MAX_NUMBERS]; // Array to store valid numbers
int count = 0; // Counter for valid numbers
long long limit = 10000000000LL; // Set a limit for the generated numbers

// Recursive function to generate numbers composed of 4s and 7s
void gen(long long number, int four, int seven) {
    // Base case: if the generated number exceeds the limit, stop recursion
    if (number > limit) {
        return;
    }
    // If the number is positive and the count of 4s equals the count of 7s, add it to the list
    if (number > 0 && four == seven) {
        if (count < MAX_NUMBERS) {
            l[count++] = number; // Store the number and increment the count
        }
    }
    // Recursively generate the next number by adding a 4
    gen(number * 10 + 4, four + 1, seven);
    // Recursively generate the next number by adding a 7
    gen(number * 10 + 7, four, seven + 1);
}

// Function to compare two long long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

// Main function to execute the number generation and find the answer
int main() {
    // Start the generation process with initial values
    gen(0, 0, 0);
    // Sort the list of generated numbers
    qsort(l, count, sizeof(long long), compare);
    
    // Read an integer input from the user
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    
    // Iterate through the sorted list to find the smallest number greater than or equal to n
    for (int i = 0; i < count; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    
    // Print the result
    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
