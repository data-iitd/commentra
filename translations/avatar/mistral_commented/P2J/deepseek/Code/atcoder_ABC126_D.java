import java.util.*;

class Node {
    int val;
    boolean color;
    List<Node> adjacencies;

    Node(int val) {
        this.val = val;
        this.color = false;
        this.adjacencies = new ArrayList<>();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Set the maximum recursion depth to 10^5
        System.setSecurityManager(new SecurityManager() {
            @Override
            public void checkLimit(Permission perm) {
                if (perm instanceof RuntimePermission && perm.getName().equals("setSecurityInfo")) {
                    super.checkPermission(perm);
                }
            }
        });
        System.setRecursionLimit(100000);

        // Read input and initialize nodes
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i + 1);
        }

        // Read edges and add adjacencies to nodes
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            int w = scanner.nextInt();
            nodes[u].adjacencies.add(nodes[v]);
            nodes[v].adjacencies.add(nodes[u]);
        }

        // Set the root node and color it
        Node root = nodes[0];
        root.color = true;

        // Traverse the graph and color nodes based on their distance from the root
        Set<Node> visited = new HashSet<>();
        traverse(root, 0, root.color, visited, nodes);

        // Print the color of each node
        for (Node node : nodes) {
            if (node.color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }

    private static void traverse(Node node, int distance, boolean rootColor, Set<Node> visited, Node[] nodes) {
        // Check if node has already been visited
        if (visited.contains(node)) {
            return;
        }
        // Mark node as visited
        visited.add(node);
        // Color node based on its distance from the root
        for (Node adj : node.adjacencies) {
            int adjDistance = 0; // Assuming weight is 1 for simplicity
            if ((distance + adjDistance) % 2 == 0) {
                adj.color = rootColor;
            } else {
                adj.color = !rootColor;
            }
            traverse(adj, distance + adjDistance, rootColor, visited, nodes);
        }
    }
}
