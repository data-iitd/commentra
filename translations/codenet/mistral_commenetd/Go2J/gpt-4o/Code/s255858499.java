import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new scanner to read input from stdin
        Scanner sc = new Scanner(System.in);
        
        // Read the first two integers from stdin and store them in variables a and b
        int a = sc.nextInt(); // Read the first integer
        int b = sc.nextInt(); // Read the second integer

        // Check if the product of a and b is odd or even
        if (a * b % 2 != 0) {
            // If the product is odd, print "Odd" to stdout
            System.out.println("Odd");
        } else {
            // If the product is even, print "Even" to stdout
            System.out.println("Even");
        }
        
        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
