#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long prod(int *arr, int size) {
    long long result = 1;
    for (int i = 0; i < size; i++) {
        result *= arr[i];
    }
    return result;
}

int main() {
    char a[100]; // Assuming the input string will not exceed 99 characters
    fgets(a, sizeof(a), stdin);
    
    // Remove newline character if present
    a[strcspn(a, "\n")] = 0;

    // Check if the string contains any '1' character
    if (strchr(a, '1') == NULL) {
        // If it doesn't, print 0 and exit the program
        printf("0\n");
        return 0;
    }

    // Calculate the product of the number of zeros in each segment between consecutive '1' characters
    int zeros[100]; // Array to hold the count of zeros in segments
    int count = 0;

    char *token = strtok(a, "1");
    while (token != NULL) {
        // Count the number of zeros in the segment
        int zero_count = strlen(token);
        zeros[count++] = zero_count + 1; // Add 1 for the segment itself
        token = strtok(NULL, "1");
    }

    // Calculate the product of the counts
    long long product_of_zeros = prod(zeros, count);

    // Finally, print the result
    printf("%lld\n", product_of_zeros);

    return 0;
}
