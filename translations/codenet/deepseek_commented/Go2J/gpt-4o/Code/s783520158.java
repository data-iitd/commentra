import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integer values from the standard input and assign them to a, b, and c
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if the difference between b and a is equal to the difference between c and b
        if (b - a == c - b) {
            // If the condition is true, print "YES"
            System.out.println("YES");
        } else {
            // Otherwise, print "NO"
            System.out.println("NO");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
