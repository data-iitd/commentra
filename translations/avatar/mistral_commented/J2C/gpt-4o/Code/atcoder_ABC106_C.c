#include <stdio.h> // Including standard input-output library
#include <string.h> // Including string library for string manipulation

int main() { // Defining the main function
    char str[100]; // Declaring a character array to hold the input string
    long k; // Declaring a long integer for the second input
    scanf("%s", str); // Reading the first line of input as a string
    scanf("%ld", &k); // Reading the second line of input as a long integer
    int n = strlen(str); // Finding the length of the string

    for (int i = 0; i < k; i++) { // Starting a for loop to iterate through the string up to the given limit 'k'
        if (str[i] == '1') { // Checking if the current character is '1'
            if (i == k - 1) { // Checking if the current index is the last index of the array
                printf("1\n"); // If yes, print '1' and exit the function
                return 0; // Exit the function
            }
        } else {
            printf("%c\n", str[i]); // If the current character is not '1', print it to the console
            return 0; // Exit the function as soon as a non-'1' character is found
        }
    }
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
