
#include <stdio.h> // Include the necessary header file
#include <string.h> // Include the necessary header file

int main() {
    // Declare and initialize a character array to store the input string
    char c[100000];
    
    // Read a string input from the user and store it in the character array
    scanf("%s", c);
    
    // Read a long integer input from the user
    long k;
    scanf("%ld", &k);
    
    // Get the length of the input string
    int n = strlen(c);
    
    // Loop through the first k characters of the character array
    for (int i = 0; i < k; i++) {
        // Check if the current character is '1'
        if (c[i] == '1') {
            // If it's the last character in the range, print 1 and exit
            if (i == k - 1) {
                printf("1\n");
                return 0; // Exit the program
            }
        } else {
            // If the current character is not '1', print it and exit
            printf("%c\n", c[i]);
            return 0; // Exit the program
        }
    }
    
    // If the loop completes without printing 1 or a character, it means the input string does not contain '1' in the first k characters
    printf("-1\n");
    
    return 0; // Return 0 to indicate successful program execution
}
