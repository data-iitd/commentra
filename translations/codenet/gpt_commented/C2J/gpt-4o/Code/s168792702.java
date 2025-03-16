import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;

        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if the first number is less than the second, and the second is less than the third
        if (a < b && b < c) 
            System.out.println("Yes");  // If the condition is true, print "Yes"
        else 
            System.out.println("No");   // If the condition is false, print "No"
        
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
