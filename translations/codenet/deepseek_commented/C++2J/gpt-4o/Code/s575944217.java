import java.util.Scanner; // For input operations
import java.util.Arrays;  // For using Arrays utility

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the number of elements or nodes
        int[] ans = new int[n]; // Initialize an array to store the count of incoming edges for each node
        
        for (int i = 0; i < n - 1; i++) { // Loop to read edges and populate the array
            int a = scanner.nextInt(); // Read an integer
            a--; // Decrement by 1 to convert to 0-based indexing
            ans[a]++; // Increment the count of incoming edges for the node
        }
        
        for (int i = 0; i < n; i++) { // Loop to output the results
            System.out.println(ans[i]); // Print the number of incoming edges for each node
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
