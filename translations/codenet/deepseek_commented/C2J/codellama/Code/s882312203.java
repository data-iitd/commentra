#include <stdio.h>  // Include standard input-output library for printf and scanf functions
#include <string.h> // Include string library for strlen function

public class Main {
    public static void main(String[] args) {
        char s[] = new char[26]; // Declare a character array to store the input string, with a maximum size of 26 characters

        scanf("%s", s); // Read a string from the user input and store it in the array s

        // Outer loop to iterate over each character in the string s using index j
        for (int j = 0; j < strlen(s); j++) {
            // Inner loop to iterate over each character in the string s using index i
            for (int i = 0; i < strlen(s); i++) {
                // Check if the characters at positions i and j are the same, but only if i is not equal to j
                if ((i != j) && (s[i] == s[j])) {
                    System.out.println("no"); // Print "no" if a duplicate character is found and exit the program
                    return;
                }
            }
        }

        System.out.println("yes"); // Print "yes" if no duplicates are found after completing the loops
    }
}

