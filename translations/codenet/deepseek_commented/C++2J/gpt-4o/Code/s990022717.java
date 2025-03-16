import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n, k, x, and y from the standard input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        
        // Initialize the sum to 0, which will accumulate the total cost
        int sum = 0;

        // Loop through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            // If the current number i is greater than k, add y to sum
            // Otherwise, add x to sum
            if (i > k) {
                sum += y;
            } else {
                sum += x;
            }
        }

        // Output the total sum, which is the cost calculated based on the input parameters
        System.out.println(sum);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
