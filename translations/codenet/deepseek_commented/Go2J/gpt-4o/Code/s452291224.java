import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables A, B, and C
        int A, B, C;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from the standard input and assign them to A, B, and C
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        
        // Check if the expression C-A+B is less than 0
        if (C - A + B < 0) {
            // If true, print "0"
            System.out.println("0");
        } else {
            // Otherwise, print the value of C-A+B
            System.out.println(C - A + B);
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
