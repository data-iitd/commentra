#include <stdio.h> // Including standard input-output header

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements in the array
    int array[n + 1]; // Initializing an array of size n+1

    // Populating the array with integers from the user input
    for (int i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }

    int odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Initializing variables to count odd and even numbers and their indices

    // Counting the number of odd and even numbers and recording their indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }

    // Comparing the counts of odd and even numbers and printing the index of the majority
    if (odd > even) {
        printf("%d\n", even_ind);
    } else {
        printf("%d\n", odd_ind);
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
