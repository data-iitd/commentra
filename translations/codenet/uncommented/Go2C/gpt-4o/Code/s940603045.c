#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define MAX_LEN 10000

// Function to calculate the sum of digits
int sum_of_digits(const char *str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - '0';
    }
    return sum;
}

int main() {
    char N[MAX_LEN];
    
    // Initialize random seed
    srand(time(NULL));

    // Read input
    if (fgets(N, sizeof(N), stdin) == NULL) {
        perror("Error reading input");
        return EXIT_FAILURE;
    }
    
    // Remove newline character if present
    size_t len = strlen(N);
    if (len > 0 && N[len - 1] == '\n') {
        N[len - 1] = '\0';
    }

    // Calculate the sum of digits
    int n = sum_of_digits(N);
    
    // Convert string to integer
    int m = atoi(N);
    
    // Check divisibility
    if (m % n == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
