import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        int i = 1; // Declare and initialize the case number
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Start an infinite loop
        while (true) {
            int input = scanner.nextInt(); // Read an integer from the user
            if (input == 0) { // Check if the input is 0
                break; // Exit the loop if the input is 0
            }
            System.out.printf("Case %d: %d%n", i, input); // Print the current case number and input value
            i++; // Increment the case number
        }
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
