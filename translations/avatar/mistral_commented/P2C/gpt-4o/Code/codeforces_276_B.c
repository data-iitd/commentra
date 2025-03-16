#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int main() {
    // Initialize an array to store input elements
    char s[MAX_CHAR];
    
    // Read input string
    scanf("%s", s);
    
    // Initialize an array to store the count of each unique element
    int dt[MAX_CHAR] = {0};
    
    // Set a boolean variable 'x' to 1 (true) to indicate whether there is an odd count element in the list
    int x = 1;
    
    // Iterate through each character in the string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        // Increment the count of the character in the dictionary
        dt[(int)s[i]]++;
    }
    
    // Initialize a counter 'cnt' to 0
    int cnt = 0;
    
    // Iterate through each possible character
    for (int i = 0; i < MAX_CHAR; i++) {
        // If the count is odd
        if (dt[i] % 2 != 0) {
            // If 'cnt' is less than 1, increment 'cnt' by 1
            if (cnt < 1) {
                cnt++;
            } else {
                // If 'cnt' is already greater than or equal to 1, set 'x' to 0 (false) and break the loop
                x = 0;
                break;
            }
        }
    }
    
    // After the loop, check the value of 'x'
    if (x) {
        // If it is true, print "First"
        printf("First\n");
    } else if (!x && strlen(s) % 2 == 0) {
        // If it is false and the length of the string 's' is even, print "Second"
        printf("Second\n");
    } else if (!x && strlen(s) % 2 != 0) {
        // If it is false and the length of the string 's' is odd, print "First"
        printf("First\n");
    }

    return 0;
}

// <END-OF-CODE>
