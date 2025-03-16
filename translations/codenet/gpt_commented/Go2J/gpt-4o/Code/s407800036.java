import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables A, B, and C to hold integer values
        int A, B, C;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from standard input
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        
        // Check if C is within the range defined by A and B (inclusive)
        if (C >= A && C <= B) {
            // If C is within the range, print "Yes"
            System.out.println("Yes");
        } else {
            // If C is outside the range, print "No"
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
