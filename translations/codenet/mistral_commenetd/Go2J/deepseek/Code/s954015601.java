import java.util.*;

public class Main {
    // Function to generate unique id based on two integers
    static int genid(int a, int b) {
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        // Multiply the larger number by 100000 and add the smaller number
        return a * 100000 + b;
    }

    // Main function
    public static void main(String[] args) {
        // Read the number of edges in the graph
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize an adjacency list and a 2D array to store the edges between nodes
        List<int[]> ab = new ArrayList<>(N - 1);
        List<List<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; i++) {
            // Read two integers representing the nodes connected by an edge
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            // Store the nodes and their indices in the ab array
            ab.add(new int[]{a, b});
            // Add the edge to the adjacency list
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        // Initialize a map to store the colors of each connected component
        Map<Integer, Integer> colors = new HashMap<>();
        // Initialize a queue to perform DFS
        Queue<int[]> q = new LinkedList<>();
        // Add the first node to the queue with initial color and parent node set to -1
        q.add(new int[]{0, -1, -1});
        while (!q.isEmpty()) {
            // Dequeue the current node, its color, and its parent node
            int[] currentNodeInfo = q.poll();
            int currentNode = currentNodeInfo[0];
            int usedColor = currentNodeInfo[1];
            int parentNode = currentNodeInfo[2];
            // Set the color of the current node to the next available color
            int color = 1;
            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue;
                }
                // If the color of the current node is the same as the color of the child node, increment the color
                if (color == usedColor) {
                    color++;
                }
                // Assign the color to the child node and add it to the queue with the current node as its parent node
                colors.put(genid(currentNode, childNode), color);
                q.add(new int[]{childNode, color, currentNode});
                // Increment the color for the next iteration
                color++;
            }
        }

        // Initialize a variable to store the maximum number of edges in a connected component
        int K = -1;
        // Iterate through all nodes in the graph and update the maximum number of edges if necessary
        for (int i = 0; i < N; i++) {
            int t = edges.get(i).size();
            if (t > K) {
                K = t;
            }
        }
        // Print the maximum number of edges in a connected component
        System.out.println(K);

        // Iterate through all edges in the graph and print their colors
        for (int[] edge : ab) {
            System.out.println(colors.get(genid(edge[0], edge[1])));
        }
    }
}
