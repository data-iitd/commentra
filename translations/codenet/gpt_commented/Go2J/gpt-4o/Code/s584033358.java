import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables n and k
        int n, k;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from standard input
        // n represents the total number of items, and k represents a threshold value
        n = scanner.nextInt();
        k = scanner.nextInt();
        
        // Check if k is less than or equal to half of n (rounded up)
        if (k <= (n + n % 2) / 2) {
            // If the condition is true, print "YES"
            System.out.println("YES");
        } else {
            // If the condition is false, print "NO"
            System.out.println("NO");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
