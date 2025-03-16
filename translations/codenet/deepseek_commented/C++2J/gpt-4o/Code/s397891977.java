import java.util.Scanner; // Step 1: Import the Scanner class for input operations

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 3: Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int r = scanner.nextInt(); // Read an integer input from the user

        System.out.println(r * r); // Step 4: Calculate the square of the input and output the result
        scanner.close(); // Close the scanner to prevent resource leaks
    }
} // End of the Main class
// <END-OF-CODE>
