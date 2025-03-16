#include <stdio.h>

int main() {
    // Read three integers from the standard input
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Sort the integers in ascending order
    if (a > b) {
<<<<<<< HEAD
        int temp = a; a = b; b = temp; // Swap a and b if a is greater than b
    }
    if (b > c) {
        int temp = b; b = c; c = temp; // Swap b and c if b is greater than c
    }
    if (a > b) {
        int temp = a; a = b; b = temp; // Swap a and b again to ensure a is not greater than b after the second swap
=======
        int temp = a;
        a = b;
        b = temp; // Swap a and b if a is greater than b
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp; // Swap b and c if b is greater than c
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp; // Swap a and b again to ensure a is not greater than b after the second swap
>>>>>>> 98c87cb78a (data updated)
    }

    // Print the sorted integers
    printf("%d %d %d\n", a, b, c);
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
