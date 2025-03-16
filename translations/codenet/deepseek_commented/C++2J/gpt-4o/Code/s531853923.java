import java.util.Scanner;

public class Main {
    // Main function to execute the program
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare four integer variables to store user input
        int a, b, c, d;
        
        // Read four integers from the standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        
        // Check if the product of a and b is odd and if the sum of c and d is also odd
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            // If both conditions are true, print "No"
            System.out.println("No");
        } else {
            // Otherwise, print "Yes"
            System.out.println("Yes");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
