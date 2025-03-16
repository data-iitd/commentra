import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of S and W from a single line of input
        int S = scanner.nextInt();
        int W = scanner.nextInt();
        
        // Check if the value of W is greater than or equal to S
        // If true, print "unsafe"
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
