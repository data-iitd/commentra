// Import the itertools module for working with combinations
import java.util.stream.IntStream;

// Define a helper function 'find' to locate the indices of a character in a string
public static int[] find(String s, char ch) {
    // Use IntStream to create a list of indices where the character 'ch' appears in the string's'
    return IntStream.range(0, s.length()).filter(i -> s.charAt(i) == ch).toArray();
}

// Check if the given input is valid and execute the main logic if it is
public static void main(String[] args) {
    // Read the number of test cases 'n' from the standard input
    int n = Integer.parseInt(System.console().readLine());

    // Read the string's' from the standard input and remove any leading or trailing whitespaces
    String s = System.console().readLine().replace("", "");

    // Check if the string's' does not contain '0' character
    if (s.indexOf('0') == -1) {
        // If '0' is not present, print the result as the number of test cases minus one
        System.out.println(n - 1);
    }

    // If '0' is present, proceed with further logic
    else {
        // Find the indices of '0' character in the string's'
        int[] indices = find(s, '0');

        // Check if there is only one '0' character in the string's'
        if (indices.length == 1) {
            // If there is only one '0', print the result as the number of '1's in the string
            System.out.println(n);
        }

        // If there are multiple '0's, calculate the maximum combination score
        else {
            // Initialize the maximum combination score as 0
            int maximum = 0;

            // Generate all possible combinations of indices of '0' characters using itertools.combinations()
            for (int[] x : IntStream.range(0, indices.length).mapToObj(i -> new int[] { indices[i], indices[i + 1] }).toArray(int[][]::new)) {
                // Calculate the score for the current combination using the given formula
                int score = 2 + 2 * (Math.abs(Arrays.binarySearch(indices, x[0]) - Arrays.binarySearch(indices, x[1])) - 1) - (Math.abs(x[0] - x[1]) - 1);
                // Update the maximum combination score if the current combination score is greater
                maximum = Math.max(maximum, score);
            }

            // Print the final result which is the number of '1's in the string plus the maximum combination score
            System.out.println(s.replaceAll("0", "").length() + maximum);
        }
    }
}

