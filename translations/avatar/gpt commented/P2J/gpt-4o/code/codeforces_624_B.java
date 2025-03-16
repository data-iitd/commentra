import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Read the list of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize the previous value to infinity
        int pre = Integer.MAX_VALUE;
        
        // Initialize the answer variable to accumulate the result
        long ans = 0;
        
        // Sort the array in descending order
        Arrays.sort(a);
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        
        // Iterate through the sorted array
        for (int j = 0; j < n; j++) {
            // Calculate the current contribution to the answer
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            
            // Update the previous value for the next iteration
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        
        // Print the final accumulated answer
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
