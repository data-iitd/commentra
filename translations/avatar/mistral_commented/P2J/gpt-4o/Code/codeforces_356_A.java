import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define the number of nodes 'n' and the number of edges 'm'
        String[] input = scanner.nextLine().strip().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        
        // Initialize an output array 'out' of size 'n' with zeros
        int[] out = new int[n];
        
        // Initialize a complement array 'comp' of size 'n' with values 'i+2' for 'i' in range(n)
        int[] comp = new int[n];
        for (int i = 0; i < n; i++) {
            comp[i] = i + 2;
        }
        
        // Process each edge in the given 'm' edges
        for (int i = 0; i < m; i++) {
            // Read the left node 'l', right node 'r', and value 'x' of the current edge
            String[] edgeInput = scanner.nextLine().strip().split(" ");
            int l = Integer.parseInt(edgeInput[0]);
            int r = Integer.parseInt(edgeInput[1]);
            int x = Integer.parseInt(edgeInput[2]);
            
            // Set the initial index 't' to the left node 'l'
            int t = l;
            
            // Iterate through the nodes from 'l' to 'r'
            while (t <= r) {
                // Get the next value in the complement array 'comp'
                int nextVal = comp[t - 1];
                
                // If the current node 't' in the output array 'out' is zero and it's not the value 'x'
                if (out[t - 1] == 0 && t != x) {
                    // Update the output array 'out' with the value 'x' at index 't-1'
                    out[t - 1] = x;
                }
                
                // Update the complement array 'comp' with the next value or the value 'x' depending on the condition
                comp[t - 1] = (t >= x) ? (r + 1) : x;
                
                // Update the index 't' to the next value in the complement array 'comp'
                t = nextVal;
            }
        }
        
        // Print the output array 'out'
        for (int i = 0; i < n; i++) {
            System.out.print(out[i] + " ");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
