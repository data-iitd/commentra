#include <stdio.h>
#include <stdlib.h>

// Initialize an empty list to store valid numbers
int l[100000];
int l_size = 0;
// Set a limit for the generated numbers
long long limit = 10000000000;

// Recursive function to generate numbers composed of 4s and 7s
void gen(long long number, int four, int seven) {
    // Base case: if the generated number exceeds the limit, stop recursion
    if (number > limit) {
        return;
    }
    // If the number is positive and the count of 4s equals the count of 7s, add it to the list
    if (number > 0 && four == seven) {
        l[l_size++] = number;
    }
    // Recursively generate the next number by adding a 4
    gen(number * 10 + 4, four + 1, seven);
    // Recursively generate the next number by adding a 7
    gen(number * 10 + 7, four, seven + 1);
}

// Main function to execute the number generation and find the answer
int main() {
    // Start the generation process with initial values
    gen(0, 0, 0);
    // Sort the list of generated numbers
    qsort(l, l_size, sizeof(int), (int (*)(const void *, const void *))compare);
    // Read an integer input from the user
    int n;
    scanf("%d", &n);
    int ans = 0;
    // Iterate through the sorted list to find the smallest number greater than or equal to n
    for (int i = 0; i < l_size; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    // Print the result
    printf("%d\n", ans);
    return 0;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
