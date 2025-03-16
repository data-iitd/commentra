import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the input
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Check if 'a' is positive
        if (a > 0) {
            // If it is, print the string 'Positive'
            System.out.println("Positive");
        }
        // If 'a' is not positive, check if 'b' is non-negative
        else if (a <= 0 && b >= 0) {
            // If it is, print the string 'Zero'
            System.out.println("Zero");
        }
        // If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
        else {
            // If it is, print the string 'Negative'
            if ((a + b) % 2 == 0) {
                System.out.println("Negative");
            }
            // Otherwise, print the string 'Positive'
            else {
                System.out.println("Positive");
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
