import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static List<List<Integer>> e;
    static int n, m;

    // Function to print the edges of the graph in a readable format
    static void printEdge(List<List<Integer>> e) {
        for (int i = 1; i <= n; i++) {
            System.out.print(i + ": ");
            for (int v : e.get(i)) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    // Depth-First Search (DFS) function to count connected components in the graph
    static int dfs(int v, boolean[] visited) {
        // Mark the current node as visited
        // System.out.println(v + " " + Arrays.toString(visited));

        // Check if all nodes are visited
        boolean comp = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                comp = false;
                break;
            }
        }

        if (comp) {
            return 1;
        }

        int count = 0;
        for (int ne : e.get(v)) {
            if (visited[ne]) {
                continue;
            }
            visited[ne] = true;
            int rst = dfs(ne, visited);
            count += rst;
            visited[ne] = false;
        }
        return count;
    }

    // Main function to read input, initialize the graph, and perform DFS
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Initialize the graph edges
        e = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            e.add(new ArrayList<>());
        }

        // Read the edges and populate the graph
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            e.get(a).add(b);
            e.get(b).add(a);
        }
        // printEdge(e);

        // Initialize visited array and start DFS from node 1
        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        int count = dfs(1, visited);
        System.out.println(count);
    }
}

// <END-OF-CODE>
