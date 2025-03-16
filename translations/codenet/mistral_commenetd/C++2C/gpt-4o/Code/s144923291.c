#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT 10
#define MAX_WIDTH 10

// Function to read a string and check if it matches "snuke"
int main() {
    long long h, w; // Variables for height and width of the grid
    scanf("%lld %lld", &h, &w); // Read height and width from standard input
    char t[10], s[10] = "snuke"; // Initialize character arrays 't' and 's'
    
    for (long long i = 0; i < h; i++) { // Iterate through each row of the grid
        for (long long j = 0; j < w; j++) { // Iterate through each column of the grid
            scanf("%s", t); // Read a string from standard input
            if (strcmp(s, t) == 0) { // Check if current string matches the pattern 'snuke'
                char c = 'A' + j; // Calculate the column index 'j' of the matching character and convert it to ASCII character
                printf("%c%lld\n", c, i + 1); // Print the character and its row number to standard output
                return 0; // Exit the program if a match is found
            }
        }
    }

    return 0; // Return 0 if no match is found
}

// <END-OF-CODE>
