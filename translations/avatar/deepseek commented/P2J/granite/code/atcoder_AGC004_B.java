
import java.util.Scanner;

public class atcoder_AGC004_B{
    public static void main(String[] args) {
        // Read the values of n and x
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the list of integers a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize a 2D array b with null values
        // b[j][i] will store the minimum value in the circular array from i to j
        Integer[][] b = new Integer[n][n];
        
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
        long m = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += b[j][i];
            }
            sum += (long) x * i;
            m = Math.min(m, sum);
        }
        
        // Print the minimum value found
        System.out.println(m);
    }
}

