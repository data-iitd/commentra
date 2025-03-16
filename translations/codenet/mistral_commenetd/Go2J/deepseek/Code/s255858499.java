import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first two integers from stdin and store them in variables a and b
        int a = scanner.nextInt(); // Read the first integer from stdin
        int b = scanner.nextInt(); // Read the second integer from stdin
        
        // Check if the product of a and b is odd or even
        if (a * b % 2 != 0) {
            // If the product is odd, print "Odd" to stdout
            System.out.println("Odd");
        } else {
            // If the product is even, print "Even" to stdout
            System.out.println("Even");
        }
    }
}

