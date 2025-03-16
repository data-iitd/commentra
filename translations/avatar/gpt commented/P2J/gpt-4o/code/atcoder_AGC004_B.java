import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: n (number of elements) and x (a multiplier)
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the list of integers 'a' from input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize a 2D array 'b' to store minimum values
        int[][] b = new int[n][n];
        
        // Fill the 2D array 'b' with minimum values from 'a'
        for (int i = 0; i < n; i++) {
            int m = a[i];  // Start with the current element
            for (int j = 0; j < n; j++) {
                int k = i - j;  // Calculate the index to wrap around
                if (k < 0) {
                    k += n;  // Wrap around if index is negative
                }
                m = Math.min(m, a[k]);  // Update m to be the minimum value found
                b[j][i] = m;  // Store the minimum value in the 2D array 'b'
            }
        }
        
        // Initialize a large value for comparison
        long minSum = Long.MAX_VALUE;
        
        // Calculate the minimum sum of elements in each row of 'b' plus the weighted index
        for (int i = 0; i < n; i++) {
            long rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += b[i][j];  // Sum the elements in the row
            }
            minSum = Math.min(minSum, rowSum + x * i);  // Update minSum with the minimum found
        }
        
        // Print the final minimum value
        System.out.println(minSum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
