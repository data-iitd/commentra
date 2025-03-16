import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input values: n (number of elements) and x (a multiplier)
        int n = sc.nextInt();
        int x = sc.nextInt();
        
        // Read the list of integers 'a' from input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize a 2D list 'b' with None values to store minimum values
        int[][] b = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = 0;
            }
        }
        
        // Fill the 2D list 'b' with minimum values from 'a'
        for (int i = 0; i < n; i++) {
            int m = a[i];  // Start with the current element
            for (int j = 0; j < n; j++) {
                int k = i - j;  // Calculate the index to wrap around
                if (k < 0) {
                    k += n;  // Wrap around if index is negative
                }
                m = Math.min(m, a[k]);  // Update m to be the minimum value found
                b[j][i] = m;  // Store the minimum value in the 2D list 'b'
        }
        
        // Initialize a large value for comparison
        int m = 1000000000;
        
        // Calculate the minimum sum of elements in each row of 'b' plus the weighted index
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += b[j][i];
            }
            m = Math.min(m, sum + x * i);  // Update m with the minimum found
        }
        
        // Print the final minimum value
        System.out.println(m);
    }
}

