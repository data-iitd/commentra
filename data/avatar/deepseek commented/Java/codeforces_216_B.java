
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    int count; // To count the number of nodes in a cycle
    boolean[] seen; // To keep track of visited nodes
    int path = 0, cycle = 1; // Constants for path and cycle
    LinkedList<LinkedList<Integer>> graph; // Graph represented as an adjacency list

    // Depth-first search method to detect cycles
    public int dfs(int child, int par) {
        if (seen[child]) return cycle; // If child is already seen, return cycle
        seen[child] = true; // Mark the child as seen
        for (Integer i : graph.get(child)) { // Iterate over neighbors of child
            if (i != par) { // Avoid going back to parent
                this.count++; // Increment count for each edge traversed
                if (dfs(i, child) == cycle) return cycle; // If cycle is detected, return cycle
            }
        }
        return path; // Return path if no cycle is detected
    }

    // Main method to handle input and output
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(); // Number of nodes
        int n = sc.nextInt(); // Number of edges
        Main ft = new Main();
        ft.graph = new LinkedList<>();
        for (int i = 0; i <= m; i++) {
            ft.graph.add(new LinkedList<>()); // Initialize adjacency list for each node
        }
        ft.seen = new boolean[m + 1]; // Initialize seen array
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt(); // Read edge from
            int y = sc.nextInt(); // Read edge to
            ft.graph.get(x).add(y); // Add edge to adjacency list of node x
            ft.graph.get(y).add(x); // Add edge to adjacency list of node y
        }
        int toremove = 0; // Initialize removal count
        for (int i = 1; i <= m; i++) {
            if (!ft.seen[i]) { // If node is not visited
                ft.count = 0; // Reset count for each DFS call
                if (ft.dfs(i, 0) == ft.cycle) { // If cycle is detected
                    if (ft.count % 2 == 1) toremove++; // Increment removal count if cycle length is odd
                }
            }
        }
        if ((m - toremove) % 2 == 1) toremove++; // Adjust removal count if total nodes minus removed nodes is odd
        System.out.println(toremove); // Print the final removal count
    }
}

