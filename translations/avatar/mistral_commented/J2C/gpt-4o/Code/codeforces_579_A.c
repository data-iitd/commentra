#include <stdio.h> // Including the standard input-output library.

int main() { // Starting the main function.
    int n; // Declaring an integer variable n to store the user input.
    scanf("%d", &n); // Reading the integer input n from the user using scanf.

    char s[32]; // Declaring a character array to store the binary representation (assuming a maximum of 32 bits).
    int index = 0; // Initializing an index variable to keep track of the position in the array.

    while (n > 0) { // Starting a while loop that continues as long as n is greater than zero.
        int x = n % 2; // Calculating the last bit of the binary representation of n.
        s[index++] = x + '0'; // Appending the calculated bit to the array s (converting int to char).
        n /= 2; // Updating the value of n by dividing it by 2.
    }

    int ans = 0; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation.

    // Since the bits are stored in reverse order, we need to count from the end of the string.
    for (int i = 0; i < index; i++) { // Starting a for loop that iterates through each character in the array s.
        if (s[i] == '1') { // Checking if the current character is '1'.
            ans++; // If the character is '1', incrementing the value of ans by 1.
        }
    }

    printf("%d\n", ans); // Printing the value of ans to the standard output stream using printf.

    return 0; // Returning 0 to indicate successful completion of the program.
}

// <END-OF-CODE>
