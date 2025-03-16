import java.util.Scanner;  // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read the first integer
        int k = scanner.nextInt();  // Read the second integer
        
        if (n % k == 0) {            // Check if n is divisible by k
            System.out.println("0"); // If true, print 0
        } else {
            System.out.println("1"); // If false, print 1
        }
        
        scanner.close();             // Close the scanner
    }
}

// <END-OF-CODE>
