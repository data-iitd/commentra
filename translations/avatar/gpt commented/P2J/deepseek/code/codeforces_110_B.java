import java.util.Scanner;

public class LuckyString {
    public static void main(String[] args) {
        // Define a constant string containing the characters 'a', 'b', 'c', and 'd'
        final String LUCKY = "abcd";

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read an integer input from the user, which determines the length of the output string
        int n = scanner.nextInt();

        // Close the scanner to free up resources
        scanner.close();

        // Initialize an empty string to store the result
        StringBuilder s = new StringBuilder();

        // Loop through a range of 'n' to build the output string
        for (int i = 0; i < n; i++) {
            // Append the character from LUCKY based on the current index modulo 4
            // This ensures that the characters 'a', 'b', 'c', 'd' are repeated in the output
            s.append(LUCKY.charAt(i % 4));
        }

        // Print the final constructed string
        System.out.println(s.toString());
    }
}
