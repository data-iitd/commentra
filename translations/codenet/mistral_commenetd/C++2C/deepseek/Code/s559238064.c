#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if there are any consecutive identical characters in the string
bool is_good(const char* z, int a) {
    for (int i = 0; i < a - 1; i++) {
        if (z[i] == z[i + 1]) {
            return false; // Found consecutive identical characters
        }
    }
    return true; // No consecutive identical characters found
}

int main() {
    char z[101]; // Initialize character array to store input string
    int a; // Variable to store size of the string

    // Read input string from standard input
    scanf("%s", z);
    // Assign size of the string to variable 'a'
    a = strlen(z);

    // Check if there are any consecutive identical characters in the string
    if (is_good(z, a)) {
        // If no consecutive identical characters are found, print "Good"
        printf("Good\n");
    } else {
        // If yes, print "Bad" and exit the program
        printf("Bad\n");
    }

    return 0;
}
