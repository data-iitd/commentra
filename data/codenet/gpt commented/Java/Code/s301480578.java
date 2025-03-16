import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        
        // Initialize an array to hold the heights
        int[] h = new int[n];
        
        // Read the heights into the array
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
        }
        
        // Initialize a variable to keep track of the maximum count of consecutive non-increasing heights
        int max = 0;
        
        // Iterate through the array to find the longest sequence of non-increasing heights
        for (int l = 0; l < n - 1; l++) {
            // Initialize a count for the current sequence
            int count = 0;
            
            // Count how many consecutive heights are non-increasing
            while (l < n - 1 && h[l] >= h[l + 1]) {
                l++;
                count++;
            }
            
            // Update the maximum count if the current count is greater
            max = Math.max(max, count);
        }
        
        // Print the maximum count of consecutive non-increasing heights
        System.out.println(max);
    }
}
