import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read the first integer from input
        int a = sc.nextInt();
        // Read the second integer from input
        int b = sc.nextInt();

        // Check if the product of a and b is odd
        if (a * b % 2 != 0) {
            // If the product is odd, print "Odd"
            System.out.println("Odd");
        } else {
            // If the product is even, print "Even"
            System.out.println("Even");
        }

        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
