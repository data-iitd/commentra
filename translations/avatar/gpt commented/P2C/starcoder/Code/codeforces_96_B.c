#include <stdio.h>
#include <stdlib.h>

// Function to generate numbers composed of 4s and 7s
void gen(int number, int four, int seven) {
    // Base case: if the generated number exceeds the limit, stop recursion
    if (number > 10000000000) {
        return;
    }
    // If the number is positive and the count of 4s equals the count of 7s, add it to the list
    if (number > 0 && four == seven) {
        printf("%d\n", number);
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
    // Read an integer input from the user
    int n;
    scanf("%d", &n);
    // Iterate through the sorted list to find the smallest number greater than or equal to n
    int ans = 0;
    for (int val = 0; val < 10000000000; val++) {
        if (val >= n) {
            ans = val;
            break;
        }
    }
    // Print the result
    printf("%d\n", ans);
    return 0;
}

