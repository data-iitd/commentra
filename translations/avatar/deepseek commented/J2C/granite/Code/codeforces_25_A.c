
#include <stdio.h> // Include the standard input/output library

int main() {
    int n; // Declare the variable n to store the number of elements in the array
    scanf("%d", &n); // Read the number of elements from the user input

    int array[n + 1]; // Declare an array of size n+1 to store the input elements

    // Read the input elements and store them in the array
    for (int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }

    int odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Declare variables to count odd and even numbers and their indices

    // Count the number of odd and even numbers and record their indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }

    // Compare the counts of odd and even numbers and print the index of the majority
    if (odd > even) {
        printf("%d", even_ind);
    } else {
        printf("%d", odd_ind);
    }

    return 0; // Return 0 to indicate successful execution of the program
}
