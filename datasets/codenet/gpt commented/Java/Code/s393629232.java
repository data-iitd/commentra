import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements to be processed
        int n = sc.nextInt();
        
        // Initialize maxv to the smallest possible integer value
        int maxv = Integer.MIN_VALUE;
        
        // Read the first element and initialize minv with it
        int minv = sc.nextInt();
        
        // Loop through the remaining elements
        for (int i = 1; i < n; i++) {
            // Read the next integer input
            int ri = sc.nextInt();
            
            // Update maxv with the maximum difference between the current element and the minimum value seen so far
            maxv = Math.max(maxv, ri - minv);
            
            // Update minv to be the smallest value encountered so far
            minv = Math.min(minv, ri);
        }
        
        // Output the maximum difference found
        System.out.println(maxv);
        
        // Close the scanner to free up resources
        sc.close();
    }
}
