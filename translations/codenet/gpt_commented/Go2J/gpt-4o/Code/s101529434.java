import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables K and X to hold input values
        int K, X;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from standard input
        K = scanner.nextInt();
        X = scanner.nextInt();
        
        // Check if 500 times K is greater than or equal to X
        if (500 * K >= X) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
