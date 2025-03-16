import java.util.Scanner; // Import the Scanner class for input operations.

public class Main { // Define the Main class.
    public static void main(String[] args) { // The main method is the entry point of the program.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input.
        
        int A, B; // Declare two integer variables A and B.
        A = scanner.nextInt(); // Take input from the user for variable A.
        B = scanner.nextInt(); // Take input from the user for variable B.
        
        int C = A + B; // Calculate the sum of A and B and store it in variable C.
        
        // Check if neither A, B, nor the sum C is divisible by 3.
        if (A % 3 != 0 && B % 3 != 0 && C % 3 != 0) {
            System.out.println("Impossible"); // If the condition is true, print "Impossible" to the console.
        } else {
            System.out.println("Possible"); // Otherwise, print "Possible" to the console.
        }
        
        scanner.close(); // Close the scanner to prevent resource leaks.
    }
}

// <END-OF-CODE>
