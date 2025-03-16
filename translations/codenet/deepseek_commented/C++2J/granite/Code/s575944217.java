
import java.util.*; // Import necessary libraries

public class s575944217{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner object for input
        int n = sc.nextInt(); // Read the number of elements or nodes
        int[] ans = new int[n]; // Initialize an array to store the count of incoming edges for each node
        for (int i = 0; i < n - 1; i++) { // Loop to read edges and populate the array
            int a = sc.nextInt() - 1; // Read an integer and decrement by 1 to convert to 0-based indexing
            ans[a]++; // Increment the count of incoming edges for the node
        }
        for (int i = 0; i < n; i++) { // Loop to output the results
            System.out.println(ans[i]); // Print the number of incoming edges for each node
        }
    }
}
