import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    // Define a helper method 'find' to locate the indices of a character in a string
    public static List<Integer> find(String s, char ch) {
        // Use a list to store the indices where the character 'ch' appears in the string 's'
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch) {
                indices.add(i);
            }
        }
        return indices;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases 'n' from the standard input
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Read the string 's' from the standard input and remove any leading or trailing whitespaces
        String s = scanner.nextLine().replace(" ", "");

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
                // Initialize the maximum combination score as 0
                int maximum = 0;

                // Generate all possible combinations of indices of '0' characters
                for (int i = 0; i < indices.size(); i++) {
                    for (int j = i + 1; j < indices.size(); j++) {
                        // Calculate the score for the current combination using the given formula
                        int score = 2 + 2 * (Math.abs(i - j) - 1) - (Math.abs(indices.get(i) - indices.get(j)) - 1);
                        // Update the maximum combination score if the current combination score is greater
                        maximum = Math.max(maximum, score);
                    }
                }

                // Print the final result which is the number of '1's in the string plus the maximum combination score
                System.out.println(s.length() - s.replace("1", "").length() + maximum);
            }
        }
    }
}
