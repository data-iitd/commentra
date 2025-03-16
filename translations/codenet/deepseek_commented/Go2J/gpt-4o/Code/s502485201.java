import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare integer variables to hold input values
        int r, d, x;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from standard input
        r = scanner.nextInt();
        d = scanner.nextInt();
        x = scanner.nextInt();
        
        // Start a loop that will run 10 times
        for (int i = 0; i < 10; i++) {
            // Update the value of x using the formula r*x - d
            x = r * x - d;
            // Print the updated value of x
            System.out.println(x);
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
