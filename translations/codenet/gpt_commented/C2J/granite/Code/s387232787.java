
import java.util.Scanner;

public class s387232787{
    public static void main(String[] args) {
        // Declare an array to hold the count of each letter (a-z)
        int[] c = new int[26];

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read strings from standard input until EOF
        while (scanner.hasNext()) {
            // Read the next string from the input
            String str = scanner.next();

            // Iterate through each character in the string
            for (int i = 0; i < str.length(); i++) {
                // Check if the character is a lowercase letter
                if ('a' <= str.charAt(i) && str.charAt(i) <= 'z') {
                    // Increment the count for the corresponding letter
                    c[str.charAt(i) - 'a']++;
                } 
                // Check if the character is an uppercase letter
                else if ('A' <= str.charAt(i) && str.charAt(i) <= 'Z') {
                    // Increment the count for the corresponding letter (converted to lowercase)
                    c[str.charAt(i) - 'A']++;
                }
            }
        }

        // Print the count of each letter from 'a' to 'z'
        for (int i = 0; i < 26; i++) {
            System.out.println((char)('a' + i) + " : " + c[i]); 
        }
    }
}
