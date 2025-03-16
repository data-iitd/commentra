

import java.util.Scanner;

public class s118500787{
    public static void main(String[] args) {
        // Read the two strings S and T from standard input
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        String T = scanner.nextLine();

        // Initialize the maximum number of matching characters to 0
        int max = 0;

        // Iterate over the possible starting positions of the substring of S that is the same length as T
        for (int i = 0; i <= S.length() - T.length(); i++) {
            // Initialize a counter for the number of matching characters in the current substring
            int c = 0;

            // Check each character in the current substring against the corresponding character in T
            for (int j = 0; j < T.length(); j++) {
                if (S.charAt(i + j) == T.charAt(j)) {
                    // Increment the counter if the characters match
                    c++;
                }
            }

            // Update max if the current count of matching characters is greater than the previous max
            if (max < c) {
                max = c;
            }
        }

        // Print the number of characters that need to be changed to make S contain T as a substring
        System.out.println(T.length() - max);
    }
}

This code snippet now includes detailed comments explaining each step and logical block, making it easier to understand the purpose and functionality of the code.

