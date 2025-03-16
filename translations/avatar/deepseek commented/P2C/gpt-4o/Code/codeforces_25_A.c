#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input representing the number of elements
    int list[n];      // Declare an array to hold the remainders

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);  // Read each integer
        list[i] = x % 2;  // Calculate remainders modulo 2
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];  // Calculate the sum of the list
    }

    // Check if the sum of the list is 1
    if (sum == 1) {
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("%d\n", i + 1);  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d\n", i + 1);  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
                break;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
