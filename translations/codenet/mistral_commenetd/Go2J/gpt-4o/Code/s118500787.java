// Importing required packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read two strings S and T
        String S = scanner.nextLine();
        String T = scanner.nextLine();

        // Initialize max as 0
        int max = 0;

        // Loop through all possible substrings of S with length equal to T
        for (int i = 0; i <= S.length() - T.length(); i++) {
            // Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
            int c = 0;

            // Check character by character for matching characters
            for (int j = 0; j < T.length(); j++) {
                // If current characters match, increment counter c
                if (S.charAt(i + j) == T.charAt(j)) {
                    c++;
                }
            }

            // If current substring has more matching characters than the current max, update max
            if (max < c) {
                max = c;
            }
        }

        // Print the length of the shortest substring of S that matches T with all characters
        System.out.println(T.length() - max);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
