import java.util.Scanner;

public class LetterCount {
    public static void main(String[] args) {
        int[] alpha = new int[26];
        char ch;

        // Initialize the alpha array to zero for all elements
        for (int i = 0; i < 26; i++) {
            alpha[i] = 0;
        }

        // Read characters from the standard input until EOF
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            ch = scanner.next().charAt(0);

            // Check if the character is an alphabetic character
            if (Character.isLetter(ch)) {
                // Increment the corresponding element in alpha based on case
                if (Character.isUpperCase(ch)) {
                    alpha[ch - 'A']++;
                } else {
                    alpha[ch - 'a']++;
                }
            }
        }
        scanner.close();

        // Print the counts of each letter from 'a' to 'z'
        for (int i = 0; i < 26; i++) {
            System.out.println((char) ('a' + i) + " : " + alpha[i]);
        }
    }
}

// <END-OF-CODE>
