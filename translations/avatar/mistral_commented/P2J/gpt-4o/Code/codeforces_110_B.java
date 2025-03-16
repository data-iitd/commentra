import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define a constant string "abcd"
        final String LUCKY = "abcd";

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Ask the user to input an integer n
        int n = scanner.nextInt();

        // Initialize an empty string s
        StringBuilder s = new StringBuilder();

        // Use a for loop to iterate through the range of integers from 0 to n-1
        for (int i = 0; i < n; i++) {
            // Add the character at index i % 4 of the string LUCKY to the string s
            s.append(LUCKY.charAt(i % 4));
        }

        // Print the final string s
        System.out.println(s.toString());

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
