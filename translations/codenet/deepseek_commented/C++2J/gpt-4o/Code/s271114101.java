import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Include the Scanner class for input operations
        
        // Define the main function, which is the entry point of the program
        
        // Declare three integer variables 'a', 'b', and 'c'
        int a, b, c;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from the standard input and store them in 'a', 'b', and 'c'
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if any of the following conditions are true:
        // - a + b equals c
        // - b + c equals a
        // - a + c equals b
        if (a + b == c || b + c == a || a + c == b) {
            // If any of these conditions are true, print "Yes"
            System.out.println("Yes");
        } else {
            // Otherwise, print "No"
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
