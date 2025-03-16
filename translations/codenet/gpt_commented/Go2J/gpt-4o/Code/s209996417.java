import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the input values n and k
        Scanner scanner = new Scanner(System.in);
        double n = scanner.nextDouble();
        double k = scanner.nextDouble();
        
        // Determine the number of digits when n is represented in base k
        double x = 0.0; // Initialize x to 0, which represents the current power of k being evaluated
        
        while (true) {
            // Calculate k raised to the power of x (lower bound)
            double under = Math.pow(k, x);
            // Calculate k raised to the power of x + 1 (upper bound)
            double upper = Math.pow(k, x + 1);
            
            // Check if n falls within the range [k^x, k^(x+1))
            if (under <= n && n < upper) {
                // If it does, print the number of digits (which is x + 1) and exit the program
                System.out.println((int)(x + 1));
                return;
            }
            // Increment x to check the next power of k
            x++;
        }
    }
}
// <END-OF-CODE>
