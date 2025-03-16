
// Import the java.util.Scanner class for reading input from the standard input
import java.util.Scanner;

// Define a helper method 'find' to locate the indices of a character in a string
public static int[] find(String s, char ch) {
    // Use a for loop to iterate through the characters of the string's' and find the indices of the character 'ch'
    int[] indices = new int[s.length()];
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == ch) {
            indices[count] = i;
            count++;
        }
    }
    // Return the array of indices containing the character 'ch'
    return Arrays.copyOf(indices, count);
}

// Check if the given input is valid and execute the main logic if it is
public static void main(String[] args) {
    // Create a new instance of the Scanner class to read input from the standard input
    Scanner scanner = new Scanner(System.in);

    // Read the number of test cases 'n' from the standard input
    int n = scanner.nextInt();

    // Read the string's' from the standard input and remove any leading or trailing whitespaces
    String s = scanner.next().replaceAll("\\s", "");

    // Check if the string's' does not contain '0' character
    if (!s.contains("0")) {
        // If '0' is not present, print the result as the number of test cases minus one
        System.out.println(n - 1);

    } else {
        // If '0' is present, proceed with further logic
        // Find the indices of '0' character in the string's'
        int[] indices = find(s, '0');

        // Check if there is only one '0' character in the string's'
        if (indices.length == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            System.out.println(n);

        } else {
            // If there are multiple '0's, calculate the maximum combination score
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using itertools.combinations()
            for (int i = 0; i < indices.length; i++) {
                for (int j = i + 1; j < indices.length; j++) {
                    // Calculate the score for the current combination using the given formula
                    int score = 2 + 2 * (Math.abs(indices[i] - indices[j]) - 1) - (Math.abs(i - j) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    maximum = Math.max(maximum, score);
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            System.out.println(s.chars().filter(ch -> ch == '1').count() + maximum);
        }
    }
}

