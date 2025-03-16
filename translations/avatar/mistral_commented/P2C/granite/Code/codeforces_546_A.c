

#include <stdio.h>

int main() {
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w); // Taking three integers as input from the user

    if (1 <= k && w <= 1000) { // Input validation
        int total = 0; // Initializing the variable 'total' to zero
        for (int i = 1; i <= w; i++) { // Iterating from 1 to w (inclusive)
            total += i * k; // Adding the product of k and the current index to the total variable
        }

        if (total > n) { // Checking if the total is greater than n or not
            printf("%d", total - n); // If yes, printing the difference between total and n
        } else {
            printf("0"); // If no, printing zero
        }
    }

    return 0;
}

Translate the above C code to Java and end with comment "