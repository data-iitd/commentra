import java.util.*;

public class Main {
    static List<List<Integer>> e = new ArrayList<>();
    static int n, m;

    // Function to print the edges of the graph in a readable format
    static void printEdge(List<List<Integer>> e) {
        for (int i = 1; i < n + 1; i++) {
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
        for (int i = 1; i < n + 1; i++) {
            if (!visited[i]) {
                comp = false;
            }
        }

        if (comp) {
            return 1;
        }

        int count = 0;
        for (int ne : e.get(v)) {
            // System.out.printf("ne=%d\n", ne);
            if (visited[ne]) {
                continue;
            }
            visited[ne] = true;
            // if (cmp, _ := dfs(ne, visited, count); cmp) {
            //     count++;
            // }
            count += dfs(ne, visited);
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
        for (int i = 0; i < n + 1; i++) {
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
