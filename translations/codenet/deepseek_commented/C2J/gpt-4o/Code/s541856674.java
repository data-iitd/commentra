import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 3: Define the main method
        int N = 0; // Step 4: Declare variables
        int R = 0;

        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        N = scanner.nextInt(); // Read the first input value
        R = scanner.nextInt(); // Read the second input value

        if (N >= 10) { // Step 5: Implement conditional logic
            System.out.println(R); // If true, print the value of R
        } else {
            System.out.println(R + 100 * (10 - N)); // Otherwise, calculate and print the adjusted value of R
        }

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class

// <END-OF-CODE>
