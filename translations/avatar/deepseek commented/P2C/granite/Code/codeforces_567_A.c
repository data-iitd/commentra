

#include <stdio.h>

int main() {
    int inp, i;
    scanf("%d", &inp);  // Taking an integer input from the user
    int lista[inp];
    for (i = 0; i < inp; i++) {
        scanf("%d", &lista[i]);  // Converting the input string into a list of integers
    }

    // Iterating through the list of integers
    for (i = 0; i < inp; i++) {
        // For the first element in the list
        if (i == 0) {
            printf("%d %d\n", lista[i + 1] - lista[i], lista[inp - 1] - lista[i]);  // Printing the differences
            continue;
        }
        // For the last element in the list
        else if (i == inp - 1) {
            printf("%d %d\n", lista[inp - 1] - lista[inp - 2], lista[inp - 1] - lista[0]);  // Printing the differences
            continue;
        }
        // For other elements in the list
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            printf("%d ", lista[i + 1] - lista[i]);  // Printing the difference between the next and current integer
        }
        else {
            printf("%d ", lista[i] - lista[i - 1]);  // Printing the difference between the current and previous integer
        }
        // Printing the difference between the last and current integer or the first and current integer
        if (lista[inp - 1] - lista[i] > lista[i] - lista[0]) {
            printf("%d\n", lista[inp - 1] - lista[i]);  // Printing the difference between the last and current integer
        }
        else {
            printf("%d\n", lista[i] - lista[0]);  // Printing the difference between the first and current integer
        }
    }
    return 0;
}
