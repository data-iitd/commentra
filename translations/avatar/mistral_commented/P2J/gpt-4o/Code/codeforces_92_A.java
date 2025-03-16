import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers `n` and `m` from the standard input, separated by a space
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize a variable `i` to 1
        int i = 1;

        // The while loop starts
        while (m >= i) {
            // Subtract `i` from `m`
            m -= i;
            
            // Update the value of `i` by calculating `(i % n) + 1`
            i = (i % n) + 1;
        }

        // Once the loop finishes, print the final value of `m` to the standard output
        System.out.println(m);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
