import java.util.*;

class Node {
    int val;
    boolean color;
    List<Edge> adjacencies;

    public Node() {
        this.val = 0;
        this.color = true;
        this.adjacencies = new ArrayList<>();
    }
}

class Edge {
    Node node;
    int weight;

    public Edge(Node node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

public class GraphColoring {
    static Set<Node> visited = new HashSet<>();

    public static void traverse(Node node, int distance) {
        // Check if node has already been visited
        if (visited.contains(node)) {
            return;
        }
        // Mark node as visited
        visited.add(node);
        // Color node based on its distance from the root
        for (Edge edge : node.adjacencies) {
            Node adjNode = edge.node;
            int adjDistance = edge.weight;
            if ((distance + adjDistance) % 2 == 0) {
                adjNode.color = node.color;
            } else {
                adjNode.color = !node.color;
            }
            traverse(adjNode, distance + adjDistance);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read number of nodes
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];

        // Initialize nodes
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i].val = i + 1; // Set the value of the node
        }

        // Read edges and add adjacencies to nodes
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            Node nodeU = nodes[u - 1];
            Node nodeV = nodes[v - 1];
            nodeU.adjacencies.add(new Edge(nodeV, w));
            nodeV.adjacencies.add(new Edge(nodeU, w));
        }

        // Set the root node and color it
        Node root = nodes[0];
        root.color = true;

        // Traverse the graph starting from the root
        traverse(root, 0);

        // Print the color of each node
        for (Node node : nodes) {
            System.out.println(node.color ? 1 : 0);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
