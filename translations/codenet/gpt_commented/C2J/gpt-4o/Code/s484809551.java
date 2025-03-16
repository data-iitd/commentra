import java.util.Scanner;

public class Main {
    // Define constants for maximum sizes
    private static final int N_MAX = 100;
    private static final int P_MAX = 100;

    // Function to find the last occurrence of a substring within a string
    private static String strrstr(String string, String pattern) {
        int offset = 0;
        String lastP = null;

        // Loop to find the last occurrence of the pattern
        while (true) {
            int searchResult = string.indexOf(pattern, offset);
            if (searchResult == -1) {
                break; // No more occurrences found
            }
            lastP = string.substring(searchResult); // Update last found position
            offset = searchResult + 1; // Move offset to search for further occurrences
        }

        return lastP; // Return the last found position
    }

    // Function to calculate combinations C(n, r)
    private static long comb(long n, long r) {
        long result = 1;

        // Calculate the combination using the formula
        for (long i = 0; i < r; i++) {
            result *= n - i; // Multiply by decreasing values of n
            result /= i + 1; // Divide by increasing values of r
        }

        return result; // Return the result
    }

    // Function to compute the greatest common divisor (GCD) of two numbers
    private static long gcd(long m, long n) {
        long temp;

        // Euclidean algorithm to find GCD
        while (m % n != 0) {
            temp = n;
            n = m % n; // Update n to the remainder
            m = temp; // Update m to the previous n
        }

        return n; // Return the GCD
    }

    // Main function to execute the program
    public static void main(String[] args) {
        final String patternBase = "keyence"; // Define the pattern to search for
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next(); // Read the input string
        scanner.close();

        boolean found = false; // Flag to indicate if the pattern is found

        // Loop through each possible split point in the pattern
        for (int offset = 0; offset <= patternBase.length(); offset++) {
            // Split the pattern into top and bottom parts
            String top = patternBase.substring(0, offset);
            String bottom = patternBase.substring(offset);

            // Search for the top part in the input string
            int topSearchIndex = S.indexOf(top);
            if (topSearchIndex != -1) {
                // Search for the bottom part after the found top part
                String bottomSearchString = S.substring(topSearchIndex + top.length());
                String bottomSearch = strrstr(bottomSearchString, bottom);
                if (bottomSearch != null) {
                    int sepCount = 0; // Counter for separators

                    // Count the number of separators between top and bottom parts
                    if (topSearchIndex > 0) {
                        sepCount++; // Increment if there's text before the top part
                    }
                    if (topSearchIndex + top.length() < S.length() - bottom.length()) {
                        sepCount++; // Increment if there's text between top and bottom parts
                    }
                    if (bottomSearch.length() < bottom.length()) {
                        sepCount++; // Increment if there's text after the bottom part
                    }

                    // Check if the number of separators is less than or equal to 1
                    if (sepCount <= 1) {
                        found = true; // Set found flag to true
                        break; // Exit the loop as the pattern is found
                    }
                }
            }
        }

        // Output the result based on whether the pattern was found
        System.out.println(found ? "YES" : "NO");
    }
}
// <END-OF-CODE>
