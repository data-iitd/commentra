#include <stdio.h>

int main() {
    int inp; // Read an integer input (not used later in the code)
    scanf("%d", &inp);

    int lista[100]; // Assuming a maximum size of 100 for the list
    int n; // Number of elements in the list

    // Read the number of elements
    scanf("%d", &n);
    
    // Read a line of input, split it into integers, and store it in lista
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    // Iterate through the indices of the lista
    for (int i = 0; i < n; i++) {
        // Handle the first element in the list
        if (i == 0) {
            // Calculate and print the difference between the second and first elements,
            // and the difference between the last and first elements
            printf("%d %d\n", lista[i + 1] - lista[i], lista[n - 1] - lista[i]);
            continue; // Skip to the next iteration
        }
        // Handle the last element in the list
        else if (i == n - 1) {
            // Calculate and print the difference between the last and second-to-last elements,
            // and the difference between the last and the first elements
            printf("%d %d\n", lista[n - 1] - lista[n - 2], lista[n - 1] - lista[0]);
            continue; // Skip to the next iteration
        }
        // For elements in the middle of the list
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            // If the difference to the next element is smaller, print that difference
            printf("%d ", lista[i + 1] - lista[i]);
        } else {
            // Otherwise, print the difference to the previous element
            printf("%d ", lista[i] - lista[i - 1]);
        }

        // Compare the difference to the last element with the difference to the first element
        if (lista[n - 1] - lista[i] > lista[i] - lista[0]) {
            // If the difference to the last element is larger, print that difference
            printf("%d\n", lista[n - 1] - lista[i]);
        } else {
            // Otherwise, print the difference to the first element
            printf("%d\n", lista[i] - lista[0]);
        }
    }

    return 0;
}
// <END-OF-CODE>
