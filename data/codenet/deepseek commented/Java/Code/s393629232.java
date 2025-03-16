
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the sequence
        int n = sc.nextInt();
        
        // Initialize maxv to the minimum possible integer value
        // Read the first value of minv from the input
        int maxv = Integer.MIN_VALUE;
        int minv = sc.nextInt();
        
        // Loop through the sequence from 1 to n-1
        for (int i = 1; i < n; i++) {
            // Read the next element in the sequence
            int ri = sc.nextInt();
            
            // Update maxv to be the maximum of the current maxv and the difference ri - minv
            maxv = Math.max(maxv, ri - minv);
            
            // Update minv to be the minimum of the current minv and the current ri
            minv = Math.min(minv, ri);
        }
        
        // Print the maximum difference found
        System.out.println(maxv);
        
        // Close the Scanner to free up resources
        sc.close();
    }
}

