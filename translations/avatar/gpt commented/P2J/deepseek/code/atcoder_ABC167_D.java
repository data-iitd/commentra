import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for N and K
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Read the list L of length N
        int[] L = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            L[i] = scanner.nextInt();
        }
        
        // Initialize variables for path tracking and loop detection
        int[] path = new int[N + 1];
        path[0] = -1; // Insert a placeholder value at the beginning of the list
        path[1] = 1; // Start the path with the first node
        int ind = 0; // Index to track the position in the path
        int count = 0; // Not used in the current logic
        int x = 1; // Current node starting from 1
        int t = -1; // To store the index of the start of the loop if found
        boolean flag = false; // Flag to indicate if a loop is detected
        HashMap<Integer, Integer> Hash = new HashMap<>(); // Dictionary to store the last index of each node
        
        // Iterate through the nodes to detect loops
        for (int i = 1; i <= N; i++) {
            int ne = L[x]; // Get the next node from the list L
            // Check if the next node has been visited before
            if (Hash.containsKey(ne)) {
                flag = true; // Set the flag to indicate a loop is found
                t = Hash.get(ne); // Store the index where the loop starts
                break; // Exit the loop since a cycle is detected
            }
            // Append the next node to the path
            path[i + 1] = ne;
            ind++; // Increment the index
            Hash.put(ne, ind); // Update the last index of the current node
            x = ne; // Move to the next node
        }
        
        // Check if a loop was detected
        if (flag) {
            int[] loop = new int[path.length - t];
            System.arraycopy(path, t, loop, 0, loop.length); // Extract the loop from the path
            // Check if K is within the length of the path
            if (K < path.length) {
                System.out.println(path[K]); // Print the K-th node in the path
            } else {
                K = K - path.length; // Adjust K to account for the full path length
                K = K % loop.length; // Get the position within the loop
                System.out.println(loop[K]); // Print the K-th node in the loop
            }
        } else {
            System.out.println(path[K - 1]); // If no loop, print the K-th node in the path
        }
        
        scanner.close();
    }
}
