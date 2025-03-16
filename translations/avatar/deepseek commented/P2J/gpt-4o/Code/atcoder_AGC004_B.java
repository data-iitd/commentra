import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n and x
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the list of integers a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize a 2D array b with Integer.MAX_VALUE values
        // b[j][i] will store the minimum value in the circular array from i to j
        int[][] b = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[j][i] = Integer.MAX_VALUE; // Set initial values to max
            }
        }
        
        // Calculate the minimum value in a circular array for each starting position i and ending position j
        for (int i = 0; i < n; i++) {
            int m = a[i];  // Initialize m with the current element
            for (int j = 0; j < n; j++) {
                int k = i - j;  // Calculate the index in the circular array
                if (k < 0) {
                    k += n;  // Adjust k if it is negative
                }
                m = Math.min(m, a[k]);  // Update m with the minimum value in the circular array
                b[j][i] = m;  // Store the minimum value in b
            }
        }
        
        // Find the minimum sum of each row in b plus x times the row index
        long minSum = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += b[i][j];
            }
            minSum = Math.min(minSum, sum + x * i);
        }
        
        // Print the minimum value found
        System.out.println(minSum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
