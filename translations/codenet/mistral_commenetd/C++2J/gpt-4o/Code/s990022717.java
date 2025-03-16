import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        int sum = 0; // Initialize sum variable to 0

        // Iterate through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            // If the current number i is greater than k, add y to the sum
            if (i > k) {
                sum += y;
            } else {
                // Otherwise, add x to the sum
                sum += x;
            }
        }

        // Output the final sum value to the standard output
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
