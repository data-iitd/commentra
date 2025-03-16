import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables K and X
        int K, X;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the standard input and assign them to K and X
        K = scanner.nextInt();
        X = scanner.nextInt();
        
        // Check if the product of 500 and K is greater than or equal to X
        if (500 * K >= X) {
            // If true, print "Yes"
            System.out.println("Yes");
        } else {
            // If false, print "No"
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
