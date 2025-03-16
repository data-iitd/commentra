#include <stdio.h>
#include <string.h>

int main() {
    // Step 1: Read a string from the user
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    
    // Step 2: Iterate through each letter from 'a' to 'z'
    for (char i = 'a'; i <= 'z'; i++) {
        // Step 3: Count how many times the current letter appears in the input string
        int a = 0;
        for (int j = 0; j < strlen(s); j++) {
            if (i == s[j]) {
                a++;
            }
        }
        
        // Step 4: If the letter does not appear in the input string, print it and break out of the loop
        if (a == 0) {
            printf("%c\n", i);
            break;
        } 
        
        // Step 5: If all letters from 'a' to 'z' appear in the input string, print "None"
        if (i == 'z') {
            printf("None\n");
            break;
        }
    }
}

// <END-OF-CODE>
