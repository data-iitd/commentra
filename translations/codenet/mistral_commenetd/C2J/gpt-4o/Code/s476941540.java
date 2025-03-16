import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int i; // Declare an integer variable 'i'
        int[] alpha = new int[26]; // Declare an integer array 'alpha' of size 26
        char ch; // Declare a character variable 'ch'

        // Initialize all elements of the array 'alpha' to zero
        for (i = 0; i < 26; i++) {
            alpha[i] = 0;
        }

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Start an infinite loop
        while (true) {
            // Read a character from the standard input
            ch = scanner.next().charAt(0);

            // If the character read is End-Of-File (EOF), break the loop
            if (ch == 0) break; // In Java, EOF can be simulated by checking for a specific condition

            // If the character is an alphabetic character
            if (Character.isAlphabetic(ch)) {
                // If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
                if (Character.isUpperCase(ch)) {
                    alpha[ch - 'A']++;
                } 
                // If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
                else {
                    alpha[ch - 'a']++;
                }
            }
        }

        // Initialize the character 'ch' with the ASCII value of 'a'
        ch = 'a';

        // Print the count of each alphabetic character and its corresponding ASCII value
        for (i = 0; i < 26; i++, ch++) {
            System.out.println(ch + " : " + alpha[i]);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
