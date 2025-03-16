import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        
        // Initialize an array to hold the input integers
        int[] a = new int[n];
        
        // Populate the array with integers from user input
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize a counter for the number of elements that are neither local minima nor maxima
        int ans = 0;
        
        // Iterate through the array from the second element to the second-to-last element
        for (int i = 1; i < n-1; i++) {
            // Check if the current element is neither the minimum nor the maximum of its neighbors
            if(a[i] != Math.min(a[i-1], Math.min(a[i], a[i+1])) &&
               a[i] != Math.max(a[i-1], Math.max(a[i], a[i+1]))) {
                // Increment the counter if the condition is met
                ans++;
            }
        }
        
        // Output the count of elements that are neither local minima nor maxima
        System.out.println(ans);
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
