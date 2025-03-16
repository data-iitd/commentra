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

int count_zeros(const char *segment) {
    int count = 0;
    while (*segment) {
        if (*segment == '0') {
            count++;
        }
        segment++;
    }
    return count;
}

int main() {
    char input[1000];  // Buffer to hold the input string
    fgets(input, sizeof(input), stdin);  // Read input (not used)
    
    fgets(input, sizeof(input), stdin);  // Read the actual string input
    input[strcspn(input, "\n")] = 0;  // Remove the newline character

    // Check if the string contains any '1's
    if (strchr(input, '1') == NULL) {
        printf("0\n");
        return 0;
    }

    // Split the string by '1's and calculate the product of counts of '0's
    char *token;
    int counts[100];  // Array to hold counts of '0's
    int count_size = 0;

    token = strtok(input, "1");
    while (token != NULL) {
        counts[count_size++] = count_zeros(token) + 1;  // Count '0's and add 1
        token = strtok(NULL, "1");
    }

    // Calculate the product of counts
    long long result = prod(counts, count_size);
    printf("%lld\n", result);

    return 0;
}
