#include <stdio.h>
#include <string.h>

public class Main {
    public static void main(String[] args) {
        // Declare a character array to hold the input string (max length 25 + 1 for null terminator)
        char[] s = new char[26];

        // Read a string from standard input
        scanf("%s", s);

        // Loop through each character in the string
        for (int j = 0; j < strlen(s); j++) {
            // Compare the current character with every other character in the string
            for (int i = 0; i < strlen(s); i++) {
                // Check if the characters are the same and they are not the same position
                if ((i != j) && (s[i] == s[j])) {
                    // If a duplicate character is found, print "no" and exit the program
                    System.out.println("no");
                    return;
                }
            }
        }

        // If no duplicates were found, print "yes"
        System.out.println("yes");
    }
}

