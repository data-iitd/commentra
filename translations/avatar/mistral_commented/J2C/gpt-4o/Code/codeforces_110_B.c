#include <stdio.h> // Include the standard input-output library

int main() {
    int n; // Declare an integer variable `n` to store the size of the character array
    int i, j; // Declare two integer variables `i` and `j` to use as loop counters
    char c[100]; // Declare a character array `c` of size 100 (assuming a maximum size)
    char p = 'a'; // Declare a character variable `p` to store the current character to be added to the array

    scanf("%d", &n); // Read an integer `n` from the standard input using scanf

    for (i = 0; i < 4; i++) { // Use a for loop to iterate through the first four elements of the array
        for (j = i; j < n; j += 4) { // Use a nested for loop to populate every fourth element of the array with the next character
            c[j] = p; // Set the current element of the array to the current character
            p++; // Increment the character to be added to the next element
        }
    }

    for (i = 0; i < n; i++) { // Use a for loop to print each character in the array to the standard output
        printf("%c", c[i]);
    }

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
