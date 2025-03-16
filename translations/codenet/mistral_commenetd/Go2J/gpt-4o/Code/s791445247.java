// by syu
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new Scanner for reading input
        Scanner in = new Scanner(System.in);
        
        // Read the first two integers from the standard input
        int n = in.nextInt();
        int k = in.nextInt();
        
        // Check if n is divisible by k
        if (n % k == 0) {
            // If it is, print 0
            System.out.println(0);
        } else {
            // If not, print 1
            System.out.println(1);
        }
        
        // Close the scanner
        in.close();
    }
}

// <END-OF-CODE>
