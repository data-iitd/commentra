#include <stdio.h>

// Initialize variables a, b, and c with user input
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Check if a is greater than b and swap if necessary
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Check if b is greater than c and swap if necessary
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }

    // Check if a is greater than b again and swap if necessary
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Print the sorted values of a, b, and c
    printf("%d %d %d\n", a, b, c);

    return 0;
}

// <END-OF-CODE>
