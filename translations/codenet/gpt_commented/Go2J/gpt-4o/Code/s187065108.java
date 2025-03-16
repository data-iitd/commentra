import java.util.Scanner;

public class Main {
    // Create a new scanner to read input from standard input
    private static Scanner sc = new Scanner(System.in);

    // Method to read an integer from input and return it
    private static int scanInt() {
        return sc.nextInt(); // Read and return the next integer
    }

    // Main method is the entry point of the program
    public static void main(String[] args) {
        // Read three integers from input: r, D, and x
        int r = scanInt();
        int D = scanInt();
        int x = scanInt();
        
        // Perform calculations and print the result for 10 iterations
        for (int i = 1; i <= 10; i++) {
            x = r * x - D; // Update x based on the formula
            System.out.println(x); // Print the current value of x
        }
    }
}

// <END-OF-CODE>
