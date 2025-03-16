
import java.util.Scanner;

public class atcoder_AGC004_B{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: n (number of elements) and x (a multiplier)
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the list of integers 'a' from input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize a 2D array 'b' with null values to store minimum values
        Integer[][] b = new Integer[n][n];
        
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
        int m = (int) 1e15;
        
        // Calculate the minimum sum of elements in each row of 'b' plus the weighted index
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += b[j][i];  // Sum the elements in the current row of 'b'
            }
            m = Math.min(m, sum + x * i);  // Update m with the minimum found
        }
        
        // Print the final minimum value
        System.out.println(m);
    }
}

// Translate the above Java code to C++ and end with comment "