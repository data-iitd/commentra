import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); // Read the number of elements
        int m = sc.nextInt(); // Read the number of comparisons
        int[] h = new int[n]; // Initialize array to store heights
        boolean[] good = new boolean[n]; // Initialize array to track "good" status
        
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt(); // Read the height of each element
            good[i] = true; // Assume all elements are initially good
        }
        
        for (int i = 0; i < m; i++) {
            int ai = sc.nextInt() - 1; // Read the first index and adjust for 0-based index
            int bi = sc.nextInt() - 1; // Read the second index and adjust for 0-based index
            
            if (h[ai] > h[bi]) { // Compare heights and update "good" status
                good[bi] = false; // Mark the second element as not good if overshadowed
            } else if (h[ai] < h[bi]) {
                good[ai] = false; // Mark the first element as not good if overshadowed
            } else {
                good[ai] = false; // Mark both elements as not good if heights are equal
                good[bi] = false;
            }
        }
        
        int ans = 0; // Initialize the count of good elements
        for (int i = 0; i < n; i++) {
            if (good[i]) { // Count the elements that are still good
                ans++;
            }
        }
        
        System.out.println(ans); // Print the number of good elements
        sc.close(); // Close the scanner
    }
}
