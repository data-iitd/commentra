// Import the java.util.Scanner class for reading input from the standard input
import java.util.Scanner;

// Define a helper function 'find' to locate the indices of a character in a string
public static int[] find(String s, char ch) {
    // Use a for loop to iterate through the characters of the string 's'
    for (int i = 0; i < s.length(); i++) {
        // Check if the current character is equal to the character 'ch'
        if (s.charAt(i) == ch) {
            // If the current character is equal to the character 'ch', return the index of the current character
            return i;
        }
    }
    // If the character 'ch' is not found in the string 's', return -1
    return -1;
}

// Check if the given input is valid and execute the main logic if it is
public static void main(String[] args) {
    // Read the number of test cases 'n' from the standard input
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    // Read the string 's' from the standard input and remove any leading or trailing whitespaces
    String s = sc.next().trim();

    // Check if the string 's' does not contain '0' character
    if (!s.contains("0")) {
        // If '0' is not present, print the result as the number of test cases minus one
        System.out.println(n - 1);
    }

    // If '0' is present, proceed with further logic
    else {
        // Find the indices of '0' character in the string 's'
        int[] indices = find(s, '0');

        // Check if there is only one '0' character in the string 's'
        if (indices.length == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            System.out.println(s.length() - 1);
        }

        // If there are multiple '0's, calculate the maximum combination score
        else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using itertools.combinations()
            for (int i = 0; i < indices.length - 1; i++) {
                for (int j = i + 1; j < indices.length; j++) {
                    // Calculate the score for the current combination using the given formula
                    int score = 2 + 2 * (Math.abs(indices[i] - indices[j]) - 1) - (Math.abs(indices[i] - indices[j]) - 1);
                    // Update the maximum combination score if the current combination score is greater
                    maximum = Math.max(maximum, score);
                }
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            System.out.println(s.length() - 1 + maximum);
        }
    }
}

