#include <stdio.h>

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Initialize an array to store the given numbers
    int w[n];

    // Read the given numbers and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // Initialize a variable 'c' with a value of 2
    int c = 2;

    // Iterate through each number in the array 'w'
    for (int i = 0; i < n; i++) {
        int number = w[i];

        // If the number is equal to 1, print the current value of 'c'
        if (number == 1) {
            printf("%d\n", c);
        }
        // If the number is even, toggle the value of 'c'
        else if (number % 2 == 0) {
            c = 3 - c;
            printf("%d\n", c);
        }
        // If the number is odd, print the current value of 'c'
        else {
            printf("%d\n", c);
        }
    }

    return 0;
}
// <END-OF-CODE>
