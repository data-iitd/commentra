import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables `a` and `b` to store input values
        int a, b;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the standard input and store them in `a` and `b`
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Check if `b` is divisible by `a` without a remainder
        if (b % a == 0) {
            // If `b` is divisible by `a`, print the sum of `a` and `b`
            System.out.println(a + b);
        } else {
            // If `b` is not divisible by `a`, print the difference between `b` and `a`
            System.out.println(b - a);
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
