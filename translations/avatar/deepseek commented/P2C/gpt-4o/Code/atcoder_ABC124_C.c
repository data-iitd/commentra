#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    int even[2] = {0, 0}; // even[0] for '0', even[1] for '1'
    int odd[2] = {0, 0}; // odd[0] for '0', odd[1] for '1'
    
    // Take a string input from the user
    printf("Enter a string: ");
    scanf("%s", s);
    
    int length = strlen(s);
    
    // Count occurrences of characters at even and odd indices
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) { // even index
            if (s[i] == '0') {
                even[0]++;
            } else {
                even[1]++;
            }
        } else { // odd index
            if (s[i] == '0') {
                odd[0]++;
            } else {
                odd[1]++;
            }
        }
    }
    
    // Calculate the minimum flips needed
    int flips1 = length - (even[0] + odd[1]); // Make all even '0' and odd '1'
    int flips2 = length - (even[1] + odd[0]); // Make all even '1' and odd '0'
    
    // Print the minimum of the two outcomes
    printf("%d\n", flips1 < flips2 ? flips1 : flips2);
    
    return 0;
}

// <END-OF-CODE>
