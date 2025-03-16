

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input representing the number of elements

    int list[n];
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        list[i] = x % 2;  // Convert to integers, and calculate remainders modulo 2
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];  // Calculate the sum of the list
    }

    if (sum == 1) {
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("%d", i + 1);  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
                return 0;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d", i + 1);  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
                return 0;
            }
        }
    }

    return 0;
}
