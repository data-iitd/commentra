import java.util.*;

public class Main {
    // Generates a unique identifier for an edge between two nodes a and b
    // by ensuring a is less than b and combining them into a single integer.
    private static int genid(int a, int b) {
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        return a * 100000 + b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes in the graph
        int N = scanner.nextInt();

        // Initialize a list to hold the edges and an adjacency list for the graph
        int[][] ab = new int[N - 1][2];
        List<List<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }

        // Read edges from input and populate the adjacency list
        for (int i = 0; i < N - 1; i++) {
            int a = scanner.nextInt() - 1; // Convert to zero-based index
            int b = scanner.nextInt() - 1; // Convert to zero-based index
            ab[i][0] = a;
            ab[i][1] = b;
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        // Map to store colors assigned to edges
        Map<Integer, Integer> colors = new HashMap<>();
        // Stack for depth-first search (DFS) with current node, used color, and parent node
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{0, -1, -1}); // Start DFS from node 0 with no used color and no parent

        // Perform DFS to assign colors to edges
        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int currentNode = current[0];
            int usedColor = current[1];
            int parentNode = current[2];
            int color = 1; // Start coloring from color 1

            // Iterate through child nodes of the current node
            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue; // Skip the parent node to avoid backtracking
                }
                if (color == usedColor) {
                    color++; // Skip the color that was used by the parent
                }
                // Assign color to the edge between currentNode and childNode
                colors.put(genid(currentNode, childNode), color);
                // Push the child node onto the stack for further exploration
                stack.push(new int[]{childNode, color, currentNode});
                color++; // Move to the next color for the next edge
            }
        }

        // Find the maximum degree of any node in the graph
        int K = -1;
        for (int i = 0; i < N; i++) {
            int degree = edges.get(i).size(); // Degree of the current node
            if (degree > K) {
                K = degree; // Update maximum degree if current node's degree is greater
            }
        }
        System.out.println(K); // Print the maximum degree

        // Print the colors assigned to each edge
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }

        scanner.close();
    }
}
// <END-OF-CODE>
