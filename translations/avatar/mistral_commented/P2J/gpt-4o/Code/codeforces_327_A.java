import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a helper function 'find' to locate the indices of a character in a string
    public static List<Integer> find(String s, char ch) {
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch) {
                indices.add(i);
            }
        }
        return indices;
    }

    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases 'n' from the standard input
        int n = Integer.parseInt(scanner.nextLine());

        // Read the string 's' from the standard input and remove any leading or trailing whitespaces
        String s = scanner.nextLine().trim();

        // Check if the string 's' does not contain '0' character
        if (!s.contains("0")) {
            // If '0' is not present, print the result as the number of test cases minus one
            System.out.println(n - 1);
        } else {
            // Find the indices of '0' character in the string 's'
            List<Integer> indices = find(s, '0');

            // Check if there is only one '0' character in the string 's'
            if (indices.size() == 1) {
                // If there is only one '0', print the result as the number of '1's in the string
                System.out.println(n);
            } else {
                // If there are multiple '0's, calculate the maximum combination score
                int maximum = 0;

                // Iterate through each combination of indices of '0' characters
                for (int i = 0; i < indices.size(); i++) {
                    for (int j = i + 1; j < indices.size(); j++) {
                        // Calculate the score for the current combination using the given formula
                        int score = 2 + 2 * (Math.abs(i - j) - 1) - (Math.abs(indices.get(i) - indices.get(j)) - 1);
                        // Update the maximum combination score if the current combination score is greater
                        maximum = Math.max(maximum, score);
                    }
                }

                // Print the final result which is the number of '1's in the string plus the maximum combination score
                System.out.println(countOccurrences(s, '1') + maximum);
            }
        }

        // Close the scanner
        scanner.close();
    }

    // Helper function to count occurrences of a character in a string
    public static int countOccurrences(String s, char ch) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == ch) {
                count++;
            }
        }
        return count;
    }
}
// <END-OF-CODE>
