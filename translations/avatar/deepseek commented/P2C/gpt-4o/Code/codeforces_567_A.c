#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Taking an integer input from the user
    int lista[n];  // Declaring an array of integers

    // Converting the input string into a list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    // Iterating through the list of integers
    for (int i = 0; i < n; i++) {
        // For the first element in the list
        if (i == 0) {
            printf("%d %d\n", lista[i + 1] - lista[i], lista[n - 1] - lista[i]);  // Printing the differences
            continue;
        }
        // For the last element in the list
        else if (i == n - 1) {
            printf("%d %d\n", lista[n - 1] - lista[n - 2], lista[n - 1] - lista[0]);  // Printing the differences
            continue;
        }
        // For other elements in the list
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            printf("%d ", lista[i + 1] - lista[i]);  // Printing the difference between the next and current integer
        } else {
            printf("%d ", lista[i] - lista[i - 1]);  // Printing the difference between the current and previous integer
        }
        // Printing the difference between the last and current integer or the first and current integer
        if (lista[n - 1] - lista[i] > lista[i] - lista[0]) {
            printf("%d\n", lista[n - 1] - lista[i]);  // Printing the difference between the last and current integer
        } else {
            printf("%d\n", lista[i] - lista[0]);  // Printing the difference between the first and current integer
        }
    }

    return 0;
}
