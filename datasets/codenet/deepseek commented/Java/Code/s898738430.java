import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        // Read the number of elements in the array
        int n = sc.nextInt();
        // Create an array to store the elements
        int[] a = new int[n];
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        // Initialize a variable to count the number of elements that are neither the minimum nor the maximum of their immediate neighbors
        int ans = 0;
        // Loop through the array from the second element to the second-to-last element
        for (int i = 1; i < n-1; i++) {
            // Check if the current element is neither the minimum nor the maximum of its immediate neighbors
            if(a[i] != Math.min(a[i-1], Math.min(a[i], a[i+1]))
                    && a[i] != Math.max(a[i-1], Math.max(a[i], a[i+1]))){
                // Increment the count if the condition is true
                ans++;
            }
        }
        // Print the result
        System.out.println(ans);
        // Close the Scanner to free up resources
        sc.close();
    }
}
