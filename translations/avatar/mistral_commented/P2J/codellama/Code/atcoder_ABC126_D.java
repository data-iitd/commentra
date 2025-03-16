
import java.util.Scanner;

// Set the maximum recursion depth to 10^5
int maxDepth = 100000;
Thread.currentThread().setStackSize(maxDepth);

// Define a Node class
class Node {
    // Initialize node attributes
    int val;
    boolean color;
    Node[] adjacencies;

    // Initialize the root node
    public Node() {
        this.val = 0;
        this.color = true;
    }
}

// Read input and initialize nodes
int n = new Scanner(System.in).nextInt();
Node[] nodes = new Node[n];
for (int i = 0; i < n; i++) {
    nodes[i] = new Node();
}

// Read edges and add adjacencies to nodes
for (int i = 0; i < n - 1; i++) {
    int u = new Scanner(System.in).nextInt();
    int v = new Scanner(System.in).nextInt();
    int w = new Scanner(System.in).nextInt();
    Node node_u = nodes[u - 1];
    Node node_v = nodes[v - 1];
    node_u.val = u;
    node_v.val = v;
    node_u.adjacencies = new Node[1];
    node_u.adjacencies[0] = node_v;
    node_v.adjacencies = new Node[1];
    node_v.adjacencies[0] = node_u;
}

// Set the root node and color it
Node root = nodes[0];
root.color = true;

// Traverse the graph and color nodes based on their distance from the root
void traverse(Node node, int distance) {
    // Check if node has already been visited
    if (visited.contains(node)) {
        return;
    }
    // Mark node as visited
    visited.add(node);
    // Color node based on its distance from the root
    for (int i = 0; i < node.adjacencies.length; i++) {
        Node adj = node.adjacencies[i];
        int adj_distance = adj.val - node.val;
        if ((distance + adj_distance) % 2 == 0) {
            adj.color = root.color;
        } else {
            adj.color = !root.color;
        }
        traverse(adj, distance + adj_distance);
    }
}

// Traverse the graph starting from the root
Set<Node> visited = new HashSet<>();
traverse(root, 0);

// Print the color of each node
for (int i = 0; i < n; i++) {
    if (nodes[i].color) {
        System.out.println(1);
    } else {
        System.out.println(0);
    }
}

