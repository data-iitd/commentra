import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;
        
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from the standard input and assign them to a, b, and c
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if c is between a and b (inclusive)
        if (c >= a && c <= b) {
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
