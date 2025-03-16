import java.util.*;

public class Main {
    // Function to generate unique id based on two integers
    private static int genid(int a, int b) {
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
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of edges in the graph
        int N = scanner.nextInt();

        // Initialize an adjacency list and a 2D array to store the edges between nodes
        int[][] ab = new int[N - 1][2];
        List<List<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            // Read two integers representing the nodes connected by an edge
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            // Store the nodes and their indices in the ab array
            ab[i][0] = a;
            ab[i][1] = b;
            // Add the edge to the adjacency list
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        // Initialize a map to store the colors of each connected component
        Map<Integer, Integer> colors = new HashMap<>();
        // Initialize a stack to perform DFS
        Stack<int[]> stack = new Stack<>();
        // Add the first node to the stack with initial color and parent node set to -1
        stack.push(new int[]{0, -1, -1});
        
        while (!stack.isEmpty()) {
            // Pop the current node, its color, and its parent node
            int[] current = stack.pop();
            int currentNode = current[0];
            int usedColor = current[1];
            int parentNode = current[2];
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
                // Assign the color to the child node and add it to the stack with the current node as its parent node
                colors.put(genid(currentNode, childNode), color);
                stack.push(new int[]{childNode, color, currentNode});
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
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }
    }
}
// <END-OF-CODE>
