// Importing required packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize scanner
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements
        int n = sc.nextInt();
        int[] a = new int[n];
        
        // Read the array elements
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Initialize answer variable
        int ans = 0;

        // Iterate through the array 'a'
        for (int i = 0; i < n; i++) {
            // Initialize left and right indices
            int l = i, r = i + 1;

            // Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
            while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
                r++;
            }

            // Increment the answer variable
            ans++;

            // Update the index 'i' to 'r' for the next iteration
            i = r;
        }

        // Print the answer
        System.out.println(ans);
        
        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
