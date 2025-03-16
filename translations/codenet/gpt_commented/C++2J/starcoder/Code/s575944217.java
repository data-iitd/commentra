import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of vertices (or nodes)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize a vector to store the count of edges for each vertex
        int[] ans = new int[n];

        // Read n-1 edges and count the occurrences for each vertex
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt(); // Read the vertex index
            a--; // Convert to 0-based index
            ans[a]++; // Increment the count for the corresponding vertex
        }

        // Output the count of edges for each vertex
        for (int i = 0; i < n; i++) {
            System.out.println(ans[i]); // Print the count for vertex i
        }
    }
}

