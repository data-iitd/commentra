import java.util.*;

// Define a class to represent each node in the graph
class Node {
    int val; // Value of the node
    boolean color; // Color of the node (True/False)
    List<Edge> a; // Adjacency list to store connected nodes and weights

    Node(int val) {
        this.val = val;
        this.color = false; // Default color is False
        this.a = new ArrayList<>();
    }
}

// Define a class to represent edges with weight
class Edge {
    Node node;
    int weight;

    Edge(Node node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of nodes from input
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];

        // Initialize nodes and store them in an array
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i + 1); // Set the value of the node
        }

        // Read edges and construct the graph
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt() - 1; // Get the first node (adjusting for 0-indexing)
            int v = scanner.nextInt() - 1; // Get the second node (adjusting for 0-indexing)
            int w = scanner.nextInt(); // Get the weight of the edge

            // Add the edge to both nodes' adjacency lists
            nodes[u].a.add(new Edge(nodes[v], w));
            nodes[v].a.add(new Edge(nodes[u], w));
        }

        // Set the root node and initialize its color
        Node root = nodes[0];
        root.color = true; // Color the root node as True
        Set<Node> nodeSet = new HashSet<>(); // Set to keep track of visited nodes

        // Define a recursive function to traverse the graph
        traverse(root, 0, root.color, nodeSet, nodes);

        // Output the color of each node
        for (Node node : nodes) {
            System.out.println(node.color ? 1 : 0); // Print 1 for True color, 0 for False color
        }
    }

    // Recursive function to traverse the graph
    private static void traverse(Node node, int distance, boolean rootColor, Set<Node> nodeSet, Node[] nodes) {
        // If the node has already been visited, return
        if (nodeSet.contains(node)) {
            return;
        } else {
            nodeSet.add(node); // Mark the node as visited
        }

        // Iterate through each adjacent node
        for (Edge edge : node.a) {
            Node adjNode = edge.node; // Get the adjacent node
            int dis = edge.weight; // Get the distance (weight) to the adjacent node
            // Determine the color of the adjacent node based on the distance
            if ((distance + dis) % 2 == 0) {
                adjNode.color = rootColor; // Same color as root
            } else {
                adjNode.color = !rootColor; // Opposite color to root
            }
            // Recursively traverse to the adjacent node
            traverse(adjNode, distance + dis, rootColor, nodeSet, nodes);
        }
    }
}
