import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements (n) from the user
        int n;
        n = sc.nextInt();
        
        // Initialize an array to hold the heights
        int[] h = new int[n];
        
        // Populate the array with heights input by the user
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }

        // Initialize variables to calculate the total increase in height
        int ans = 0; // Total increase in height
        int out = 0; // Current height level

        // Iterate through the heights to calculate the total increase
        for (int i = 0; i < h.length; i++) {
            // If the current height is greater than the previous height
            if (out < h[i]) {
                // Calculate the difference and add it to the total increase
                ans += h[i] - out;
                // Update the current height to the new height
                out = h[i];
            } else {
                // If the current height is not greater, just update the current height
                out = h[i];
            }
        }

        // Output the total increase in height
        System.out.println(ans);
    }
}
