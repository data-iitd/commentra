import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Check if the first integer 'a' is positive
        if (a > 0) {
            System.out.println("Positive");  // Output 'Positive' if 'a' is greater than 0
        } else if (a <= 0 && b >= 0) {
            System.out.println("Zero");  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
        } else {
            // If 'a' is negative and 'b' is also negative
            if ((a + b) % 2 == 0) {
                System.out.println("Negative");  // Output 'Negative' if the sum of 'a' and 'b' is even
            } else {
                System.out.println("Positive");  // Output 'Positive' if the sum of 'a' and 'b' is odd
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
