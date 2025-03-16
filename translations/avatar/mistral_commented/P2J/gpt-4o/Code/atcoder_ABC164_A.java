// Import the Scanner class for taking input
import java.util.Scanner;

public class Main {
    // Define the main method
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Get the input as two integers, S and W
        int S = scanner.nextInt();
        int W = scanner.nextInt();

        // Check if the condition S <= W is true or false and print the corresponding message
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
