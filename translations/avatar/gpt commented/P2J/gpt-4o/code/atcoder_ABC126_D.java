import java.util.*;

public class GraphColoring {
    // Define a class to represent each node in the graph
    static class Node {
        Integer val; // Value of the node
        Boolean color; // Color of the node (True/False)
        List<Edge> adjacencyList; // Adjacency list to store connected nodes and weights

        Node() {
            this.adjacencyList = new ArrayList<>();
        }
    }

    // Define a class to represent an edge
    static class Edge {
        Node node; // The adjacent node
        int weight; // The weight of the edge

        Edge(Node node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    // Set to keep track of visited nodes
    static Set<Node> visitedNodes = new HashSet<>();

    // Define a recursive function to traverse the graph
    static void traverse(Node node, int distance) {
        // If the node has already been visited, return
        if (visitedNodes.contains(node)) {
            return;
        } else {
            visitedNodes.add(node); // Mark the node as visited
        }

        // Iterate through each adjacent node
        for (Edge edge : node.adjacencyList) {
            Node adjNode = edge.node; // Get the adjacent node
            int dis = edge.weight; // Get the distance (weight) to the adjacent node
            // Determine the color of the adjacent node based on the distance
            if ((distance + dis) % 2 == 0) {
                adjNode.color = node.color; // Same color as current node
            } else {
                adjNode.color = !node.color; // Opposite color to current node
            }
            // Recursively traverse to the adjacent node
            traverse(adjNode, distance + dis);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes from input
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];

        // Initialize nodes and store them in an array
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }

        // Read edges and construct the graph
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            Node node1 = nodes[u - 1]; // Get the first node (adjusting for 0-indexing)
            Node node2 = nodes[v - 1]; // Get the second node (adjusting for 0-indexing)
            node1.val = u; // Set the value of the first node
            node2.val = v; // Set the value of the second node
            // Add the edge to both nodes' adjacency lists
            node1.adjacencyList.add(new Edge(node2, w));
            node2.adjacencyList.add(new Edge(node1, w));
        }

        // Set the root node and initialize its color
        Node root = nodes[0];
        root.color = true; // Color the root node as True

        // Start the traversal from the root node with an initial distance of 0
        traverse(root, 0);

        // Output the color of each node
        for (Node node : nodes) {
            if (node.color) {
                System.out.println(1); // Print 1 for True color
            } else {
                System.out.println(0); // Print 0 for False color
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
