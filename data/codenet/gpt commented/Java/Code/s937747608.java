import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read four integers from the user
        int a = sc.nextInt(); // First integer
        int b = sc.nextInt(); // Second integer
        int c = sc.nextInt(); // Third integer
        int d = sc.nextInt(); // Fourth integer
        
        // Calculate the products of the first two integers and the last two integers
        // Compare the two products and print the larger one
        if (a * b >= c * d) {
            // If the product of a and b is greater than or equal to the product of c and d, print a * b
            System.out.println(a * b);
        } else if (a * b < c * d) {
            // If the product of c and d is greater than the product of a and b, print c * d
            System.out.println(c * d);
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
