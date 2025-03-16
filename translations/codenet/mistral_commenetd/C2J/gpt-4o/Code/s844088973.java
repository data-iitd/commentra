import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int K = scanner.nextInt(); // Read the first integer and store it in K
        int X = scanner.nextInt(); // Read the second integer and store it in X

        for (int i = X - K + 1; i <= X + K - 1; i++) { // Start of the for loop
            System.out.print(i); // Print the current value of i
            if (i < X + K - 1) System.out.print(" "); // If i is less than X + K - 1, print a space
        }

        System.out.println(); // Print a newline character
        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
