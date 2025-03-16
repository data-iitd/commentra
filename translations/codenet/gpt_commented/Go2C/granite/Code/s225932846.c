
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable S to hold the input string
    char S[1000];
    
    // Read the input string from the standard input
    scanf("%s", S);
    
    // Iterate over even lengths of the string from 2 to the length of S
    for (int i = 2; i <= strlen(S); i = i + 2) {
        // Check if the first half of the string (up to the current length minus i)
        // is equal to the second half of the string (from the middle to the current length minus i)
        if (strncmp(S, S + (strlen(S) - i) / 2, (strlen(S) - i) / 2) == 0) {
            // If they are equal, print the length of the string minus i
            // This gives the length of the string that is not part of the repeated pattern
            printf("%d\n", strlen(S) - i);
            // Exit the loop after finding the first match
            break;
        }
    }
    
    return 0;
}
