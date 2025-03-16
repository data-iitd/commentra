import java.util.*;

class Node {
    Integer val;
    Boolean color;
    List<Pair<Node, Integer>> a;

    public Node() {
        this.val = null;
        this.color = null;
        this.a = new ArrayList<>();
    }
}

class Pair<K, V> {
    K first;
    V second;

    public Pair(K first, V second) {
        this.first = first;
        this.second = second;
    }
}

public class GraphColoring {
    static Set<Node> nodeSet = new HashSet<>();

    public static void traverse(Node node, int distance) {
        if (nodeSet.contains(node)) {
            return;
        } else {
            nodeSet.add(node);
        }
        for (Pair<Node, Integer> pair : node.a) {
            Node adjNode = pair.first;
            int dis = pair.second;
            if ((distance + dis) % 2 == 0) {
                adjNode.color = node.color;
            } else {
                adjNode.color = !node.color;
            }
            traverse(adjNode, distance + dis);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of nodes in the graph
        int n = scanner.nextInt();
        
        // Create a list to store all nodes
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }

        // Read each edge in the graph and establish connections between nodes
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            Node node1 = nodes[u - 1];
            Node node2 = nodes[v - 1];
            node1.val = u;
            node2.val = v;
            node1.a.add(new Pair<>(node2, w));
            node2.a.add(new Pair<>(node1, w));
        }

        // Set the root node to the first node in the list
        Node root = nodes[0];

        // Set the color of the root node to True
        root.color = true;

        // Call the traverse function starting from the root node with a distance of 0
        traverse(root, 0);

        // Print the color of each node
        for (int i = 0; i < n; i++) {
            Node node = nodes[i];
            if (node.color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
