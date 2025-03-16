import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of nodes N
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        // Initialize a list of deque objects to represent the graph
        List<Deque<Integer>> G = new ArrayList<Deque<Integer>>();
        for (int i = 0; i < N; i++) {
            G.add(new LinkedList<Integer>());
        }
        // Initialize an empty dictionary to store edge colors
        Map<Integer, Integer> E = new HashMap<Integer, Integer>();
        // Read edges to populate the graph and edge dictionary
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            G.get(a).add(b);
            G.get(b).add(a);
            E.put(a * N + b, 0);
            E.put(b * N + a, 0);
        }
        // Perform BFS to determine the maximum color and edge colors
        int K = bfs(0, N, G, E);
        // Print the maximum color used
        System.out.println(K);
        // Print the colors of all edges
        for (int value : E.values()) {
            System.out.println(value);
        }
    }

    // Function to perform Breadth-First Search (BFS) to color the graph
    public static int bfs(int v, int N, List<Deque<Integer>> G, Map<Integer, Integer> E) {
        // Initialize visited list to keep track of visited nodes
        boolean[] visited = new boolean[N];
        // Initialize a queue for BFS using deque
        Deque<Integer> queue = new LinkedList<Integer>();
        // Initialize the maximum color index K
        int K = -1;
        // List to store the color of each node, initialized to -1 (no color)
        int[] node2color = new int[N];
        Arrays.fill(node2color, -1);
        // Start BFS from vertex v
        queue.add(v);
        visited[v] = true;
        while (!queue.isEmpty()) {
            // Dequeue the front node
            int q = queue.removeFirst();
            // Initialize color for the current node
            int color = 0;
            // Iterate over all adjacent nodes
            for (int nex : G.get(q)) {
                if (visited[nex]) {
                    continue;
                }
                visited[nex] = true;
                color += 1;
                // Ensure the color is different from the parent node's color
                if (color == node2color[q]) {
                    color += 1;
                }
                // Assign the color to the node and record the edge color
                node2color[nex] = color;
                E.put(Math.min(q, nex) * N + Math.max(q, nex), color);
                // Enqueue the adjacent node for further exploration
                queue.add(nex);
            }
            // Update the maximum color used
            K = Math.max(K, color);
        }
        return K;
    }
}

