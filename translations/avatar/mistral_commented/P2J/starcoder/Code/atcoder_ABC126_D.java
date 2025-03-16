
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            nodes[u - 1].val = u;
            nodes[v - 1].val = v;
            nodes[u - 1].adjacencies.add(new Node[] { nodes[v - 1], w });
            nodes[v - 1].adjacencies.add(new Node[] { nodes[u - 1], w });
        }
        Node root = nodes[0];
        root.color = true;
        traverse(root, 0);
        for (Node node : nodes) {
            if (node.color) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }

    public static void traverse(Node node, int distance) {
        if (node.visited) {
            return;
        }
        node.visited = true;
        for (Node[] adj : node.adjacencies) {
            Node adjNode = adj[0];
            int adjDistance = adj[1];
            if ((distance + adjDistance) % 2 == 0) {
                adjNode.color = root.color;
            } else {
                adjNode.color =!root.color;
            }
            traverse(adjNode, distance + adjDistance);
        }
    }
}

class Node {
    public int val;
    public boolean color;
    public List<Node[]> adjacencies;
    public boolean visited;

    public Node() {
        val = 0;
        color = false;
        adjacencies = new ArrayList<Node[]>();
        visited = false;
    }
}

