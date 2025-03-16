// by syu
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner for reading input
        Scanner in = new Scanner(System.in);
        
        // Read two integers n and k from the input
        int n = in.nextInt();
        int k = in.nextInt();
        
        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0
            System.out.println(0);
        } else {
            // If n is not divisible by k, print 1
            System.out.println(1);
        }
        
        in.close(); // Close the scanner
    }
}

// <END-OF-CODE>
