import java.util.Scanner;

public class LetterCount {
    // Array to store the count of each letter (a-z)
    static int[] c = new int[26];

    public static void main(String[] args) {
        // Scanner to read input
        Scanner scanner = new Scanner(System.in);

        // Read input strings until there are no more inputs
        while (scanner.hasNext()) {
            // Read the input string
            String str = scanner.next();

            // Pointer to traverse the string
            char[] charArray = str.toCharArray();

            // Traverse each character in the string
            for (char ch : charArray) {
                // Check if the character is a lowercase letter
                if ('a' <= ch && ch <= 'z') {
                    // Increment the count for the corresponding letter
                    c[ch - 'a']++;
                }
                // Check if the character is an uppercase letter
                else if ('A' <= ch && ch <= 'Z') {
                    // Increment the count for the corresponding letter
                    c[ch - 'A']++;
                }
            }
        }

        // Print the counts for each letter from 'a' to 'z'
        for (int i = 0; i < 26; i++) {
            System.out.println((char)('a' + i) + " : " + c[i]);
        }

        // Close the scanner
        scanner.close();
    }
}
