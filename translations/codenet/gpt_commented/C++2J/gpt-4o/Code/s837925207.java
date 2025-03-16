import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int x; // Declare variable x for input
        long ans = 0; // Declare variable ans for the result

        // Read an integer input from the user
        x = scanner.nextInt();

        // Calculate the result as the sum of x, x squared, and x cubed
        ans = x + (long) Math.pow(x, 2) + (long) Math.pow(x, 3);

        // Output the calculated result to the console
        System.out.println(ans);

        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
