import java.util.Scanner;

public class LetterCount {
    public static void main(String[] args) {
        // Declare variables: 'alpha' array to count occurrences of each letter
        int[] alpha = new int[26];
        char ch;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Infinite loop to read characters until EOF (End of File) is encountered
        while (scanner.hasNext()) {
            ch = scanner.next().charAt(0); // Read a character from standard input

            // Check if the character is an alphabet letter
            if (Character.isLetter(ch)) {
                // If the character is uppercase, increment the corresponding index in the alpha array
                if (Character.isUpperCase(ch)) {
                    alpha[ch - 'A']++; // 'A' is at index 0, 'B' at index 1, ..., 'Z' at index 25
                } else {
                    // If the character is lowercase, increment the corresponding index in the alpha array
                    alpha[ch - 'a']++; // 'a' is at index 0, 'b' at index 1, ..., 'z' at index 25
                }
            }
        }

        // Print the count of each letter from 'a' to 'z'
        for (int i = 0; i < 26; i++) {
            System.out.println((char) ('a' + i) + " : " + alpha[i]); // Output the letter and its count
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
