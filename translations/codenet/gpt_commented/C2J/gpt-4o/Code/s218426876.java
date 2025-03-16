import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for iteration and sum
        int sum = 0;
        String x; // Variable to store input strings
        Scanner scanner = new Scanner(System.in);

        // Read the first input string
        x = scanner.nextLine();

        // Loop to process input until the termination condition is met
        do {
            // Iterate through the characters of the input string
            for (int i = 0; i < x.length(); i++) {
                // Convert character to integer and add to sum
                sum += x.charAt(i) - '0'; // '0' is represented by '0' in Java
            }

            // Print the sum of the digits in the string
            System.out.println(sum);

            // Reset sum for the next input
            sum = 0;

            // Read the next input string
            x = scanner.nextLine();
        } while (x.charAt(0) != '0'); // Continue until the first character is '0'

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
