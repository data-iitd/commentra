import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // The entry point of the program
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables n and m
        int n, m;

        // Read two integers from the standard input and store them in n and m variables
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
        int result = (n - 1) * (m - 1);

        // Print the result to the standard output
        System.out.println(result);

        // Close the scanner to free resources
        scanner.close();
    } // Indicate that the program has run successfully
} // End of the Main class
// <END-OF-CODE>
