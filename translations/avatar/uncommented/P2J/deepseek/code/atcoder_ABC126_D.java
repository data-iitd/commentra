import java.util.*;

class Node {
    int val;
    boolean color;
    List<Pair> a;

    Node(int val) {
        this.val = val;
        this.color = false;
        this.a = new ArrayList<>();
    }
}

class Pair {
    Node node;
    int weight;

    Pair(Node node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

public class Main {
    static int n;
    static Node[] nodes;
    static Set<Node> nodeSet = new HashSet<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i + 1);
        }
        for (int i = 0; i < n - 1; i++) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            int w = scanner.nextInt();
            nodes[u].a.add(new Pair(nodes[v], w));
            nodes[v].a.add(new Pair(nodes[u], w));
        }
        Node root = nodes[0];
        root.color = true;
        traverse(root, 0);
        for (int i = 0; i < n; i++) {
            Node node = nodes[i];
            System.out.println(node.color ? 1 : 0);
        }
    }

    static void traverse(Node node, int distance) {
        if (nodeSet.contains(node)) {
            return;
        } else {
            nodeSet.add(node);
        }
        for (Pair pair : node.a) {
            Node adjNode = pair.node;
            int dis = pair.weight;
            if ((distance + dis) % 2 == 0) {
                adjNode.color = node.color;
            } else {
                adjNode.color = !node.color;
            }
            traverse(adjNode, distance + dis);
        }
    }
}
