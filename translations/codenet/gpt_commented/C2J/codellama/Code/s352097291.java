#include <stdio.h>
#include <string.h>

public class Main {
    public static void main(String[] args) {
        // Declare a character array 'c' to store the input string and 'ans' to store the result
        char c[] = new char[11];
        char ans[] = new char[11];
        
        // Read a string input from the user
        scanf("%s", c);
        
        // Iterate through each character of the input string until the null terminator is encountered
        for (int i = 0; c[i] != '\0'; i++) {
            // If the current character is not 'B', append it to the 'ans' string
            if (c[i] != 'B') {
                ans[strlen(ans)] = c[i];
            } 
            // If the current character is 'B', remove the last character from 'ans' (if it exists)
            else {
                ans[strlen(ans) - 1] = '\0';
            }
        }
        
        // Print the resulting string after processing the input
        printf("%s\n", ans);
    }
}

