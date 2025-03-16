#include <stdio.h>
#include <string.h>

int main() {
    // Declare a character array to hold the input string
    char n[100];
    
    // Read input from the user and store it in array n
    scanf("%s", n);
    
    // Loop through the first three characters of the input string
    for (int i = 0; i < 3; i++) {
        // Check if the current character is '7'
        if (n[i] == '7') {
            // If '7' is found, print "Yes" and exit the program
            printf("Yes\n");
            return 0;
        }
    }
    
    // If '7' is not found in the first three characters, print "No"
    printf("No\n");
    
    return 0;
}
