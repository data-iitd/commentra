import java.util.Scanner;

public class CharacterCount {
    public static void main(String[] args) {
        // Initialize an array 'c' of size 26 to store the count of each character.
        int[] c = new int[26];
        Scanner scanner = new Scanner(System.in);

        // Use a loop to read strings from the standard input until the end of file is reached.
        while (scanner.hasNext()) {
            String str = scanner.next(); // Read the next string from input.
            // Use a loop to traverse the string 'str'.
            for (char p : str.toCharArray()) {
                // Use nested if conditions to check if the current character is a lowercase or uppercase letter.
                if ('a' <= p && p <= 'z') {
                    // Increment the count of the corresponding character in the 'c' array.
                    c[p - 'a']++;
                } else if ('A' <= p && p <= 'Z') {
                    // Increment the count of the corresponding character in the 'c' array.
                    c[p - 'A']++;
                }
            }
        }
        // Use a loop to print the count of each character and its corresponding character.
        for (int i = 0; i < 26; i++) {
            System.out.println((char) ('a' + i) + " : " + c[i]);
        }
        // Close the scanner to prevent resource leaks.
        scanner.close();
    }
}
// <END-OF-CODE>
