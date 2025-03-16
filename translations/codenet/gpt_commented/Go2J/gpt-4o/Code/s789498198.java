import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Check if the sum of A and B is even
        if ((A + B) % 2 == 0) {
            // If even, print the average
            System.out.println((A + B) / 2);
        } else {
            // If odd, print "IMPOSSIBLE"
            System.out.println("IMPOSSIBLE");
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
