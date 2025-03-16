import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer k from standard input
        int k = scanner.nextInt();
        
        // Initialize a variable t to 0
        long t = 0;
        
        // Loop from 1 to k
        for (int i = 1; i <= k; i++) {
            // Calculate the value of t using the current value of i and k
            t = ( (t % k) * 10 + 7 ) % k;
            
            // Check if t is a multiple of k
            if (t == 0) {
                // Print the value of i and break out of the loop
                System.out.println(i);
                return; // Exit the main method
            }
        }
        
        // If the loop completes without finding a multiple of k, print -1
        System.out.println(-1);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
