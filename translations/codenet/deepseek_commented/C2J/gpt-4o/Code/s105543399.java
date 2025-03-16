import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n, a, m, M, c, i; // Declare variables to store input, current number, min, max, and sum
        c = 0; // Initialize sum to 0
        m = 100000000; // Initialize minimum to a large positive value
        M = -100000000; // Initialize maximum to a large negative value
        
        n = scanner.nextLong(); // Read the number of elements

        // Loop through each element
        for (i = 1; i <= n; i++) {
            a = scanner.nextLong(); // Read the current number
            if (a > M) {
                M = a; // Update maximum if current number is greater
            }
            if (a < m) {
                m = a; // Update minimum if current number is smaller
            }
            c = c + a; // Add current number to sum
        }

        System.out.printf("%d %d %d\n", m, M, c); // Print the minimum, maximum, and sum of the numbers
        
        scanner.close();
    }
}

// <END-OF-CODE>
