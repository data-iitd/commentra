import java.util.Scanner;

public class GCDArray {

    // Method to compute the GCD of two integers
    public static int gcd(int a, int b) {
        // Base case: if b is 0, return a as the GCD
        if (b == 0) {
            return a;
        }
        // Recursive case: call gcd with b and the remainder of a divided by b
        return gcd(b, a % b);
    }

    // Method to compute cumulative GCD from left and right
    public static int[][] ruiseki_lr(int[] array) {
        // Define the operation to find the GCD of two numbers
        int n = array.length;
        int[][] result = new int[2][n + 1];

        // Initialize the identity element for GCD
        int e = 0;

        // Calculate cumulative GCD from the left
        for (int i = 0; i < n; i++) {
            result[0][i + 1] = gcd(result[0][i], array[i]);
        }

        // Calculate cumulative GCD from the right
        for (int i = n - 1; i >= 0; i--) {
            result[1][i] = gcd(result[1][i + 1], array[i]);
        }

        // Return both cumulative GCD arrays
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = scanner.nextInt();
        // Read the array elements from input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Compute the cumulative GCD from the left and right
        int[][] lr = ruiseki_lr(a);
        int[] left = lr[0];
        int[] right = lr[1];

        // Initialize the answer variable to store the maximum GCD found
        int ans = 0;

        // Iterate through the array to find the maximum GCD of left and right parts
        for (int i = 0; i < n; i++) {
            ans = Math.max(gcd(left[i], right[i + 1]), ans);
        }

        // Print the maximum GCD found
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
