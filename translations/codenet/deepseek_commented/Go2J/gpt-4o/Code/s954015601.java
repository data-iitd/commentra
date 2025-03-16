import java.util.*;

public class Main {
    // Generates a unique identifier for an edge between two nodes.
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
        
        // Read the number of nodes from standard input.
        int N = scanner.nextInt();

        // Initialize a list to store edges and an adjacency list for the graph.
        int[][] ab = new int[N - 1][2];
        List<List<Integer>> edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            // Read edge information and populate the adjacency list.
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            ab[i][0] = a;
            ab[i][1] = b;
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        // Initialize a map to store the color of each edge and a stack for DFS traversal.
        Map<Integer, Integer> colors = new HashMap<>();
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{0, -1, -1}); // {currentNode, usedColor, parentNode}

        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int currentNode = current[0];
            int usedColor = current[1];
            int parentNode = current[2];
            int color = 1;

            for (int childNode : edges.get(currentNode)) {
                if (childNode == parentNode) {
                    continue;
                }
                if (color == usedColor) {
                    color++;
                }
                colors.put(genid(currentNode, childNode), color);
                stack.push(new int[]{childNode, color, currentNode});
                color++;
            }
        }

        // Determine the maximum degree of any node in the graph.
        int K = -1;
        for (int i = 0; i < N; i++) {
            int t = edges.get(i).size();
            if (t > K) {
                K = t;
            }
        }
        System.out.println(K);

        // Output the colors of the edges.
        for (int i = 0; i < N - 1; i++) {
            System.out.println(colors.get(genid(ab[i][0], ab[i][1])));
        }

        scanner.close();
    }
}
