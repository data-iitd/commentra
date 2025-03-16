#include <stdio.h>

int main() {
    int n;
    // Read user input and assign it to the variable 'n'
    scanf("%d", &n);

    // Create an array 'list' with the same length as 'n'
    int list[n];

    // Read the input values and calculate the remainder when divided by 2
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        list[i] = x % 2;
    }

    // Check if the sum of all elements in the list is equal to 1
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }

    if (sum == 1) {
        // If the condition is true, print the index of the first occurrence of the number 1 in the list
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("The first number with remainder 1 is: %d\n", i + 1);
                break;
            }
        }
    } else {
        // If the condition is false, print the index of the first occurrence of the number 0 in the list
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("The first number with remainder 0 is: %d\n", i + 1);
                break;
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
