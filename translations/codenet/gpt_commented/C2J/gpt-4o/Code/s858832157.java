import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a counter variable 'i' to track the case number
        int i = 1;
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Start an infinite loop to continuously accept user input
        while (true) {
            // Read an integer input from the user
            int input = scanner.nextInt();

            // Check if the input is zero, which indicates the end of input
            if (input == 0) {
                // Exit the loop if the input is zero
                break;
            }

            // Print the case number and the input value
            System.out.printf("Case %d: %d\n", i, input);

            // Increment the case number for the next iteration
            i++;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
