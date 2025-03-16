// by syu
import java.util.Scanner; // Importing Scanner for input handling

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner to read from standard input
        Scanner in = new Scanner(System.in);
        
        // Read two integers n and k from input
        int n = in.nextInt();
        int k = in.nextInt();
        
        // Check if n is divisible by k
        if (n % k == 0) {
            // If divisible, print 0
            System.out.println(0);
        } else {
            // If not divisible, print 1
            System.out.println(1);
        }
        
        in.close(); // Close the scanner
    }
}

// <END-OF-CODE>
