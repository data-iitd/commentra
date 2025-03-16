
#include <stdio.h>

// Define constants for modulo operation and factorial limit
#define mod 998244353
#define facNum 300001

int main() {
    // Initialize a new scanner for reading input
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int N;
    fscanf(input, "%d", &N);
    int sum = 0;
    
    // Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue; // Skip numbers divisible by 3 or 5
        }
        sum += i; // Add the number to the sum
    }
    
    // Output the final sum
    fprintf(output, "%d", sum);
    
    fclose(input);
    fclose(output);
    
    return 0;
}

// 