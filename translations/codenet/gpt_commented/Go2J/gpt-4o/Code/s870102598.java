import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables a, b, and c
        int a, b, c;
        
        // Create a Scanner object to read input values
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for a, b, and c from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if c is within the range [a, b]
        if (c >= a && c <= b) {
            // If c is within the range, print "Yes"
            System.out.println("Yes");
        } else {
            // If c is outside the range, print "No"
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
