// Import the Scanner class for reading input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare two integer variables "n" and "k"
        int n, k;
        
        // Read the values of "n" and "k" from the standard input
        n = scanner.nextInt();
        k = scanner.nextInt();
        
        // Check if the value of "k" is less than or equal to the middle index of the slice "n"
        if (k <= (n + n % 2) / 2) {
            // If the condition is true, print "YES" to the standard output
            System.out.println("YES");
        } else {
            // If the condition is false, print "NO" to the standard output
            System.out.println("NO");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
