import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int A = scanner.nextInt(); // Read the first integer
        int B = scanner.nextInt(); // Read the second integer
        
        if (A < 10 && B < 10) { // Check if both A and B are less than 10
            System.out.println(A * B); // If true, print the product of A and B
        } else { // If the condition is false
            System.out.println("-1"); // Print -1 as an error message
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
