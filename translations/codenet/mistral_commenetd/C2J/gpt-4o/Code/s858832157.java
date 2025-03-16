import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize variables
        int i = 1; // Initialize counter variable i to 1
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input

        while (true) {
            // Read user input and store it in the Input variable
            int Input = scanner.nextInt();

            // Check if user input is 0
            if (Input == 0) {
                // If user input is 0, break out of the loop
                break;
            }

            // Print the case number and user input
            System.out.printf("Case %d: %d\n", i, Input);

            // Increment the counter variable i
            i++;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
